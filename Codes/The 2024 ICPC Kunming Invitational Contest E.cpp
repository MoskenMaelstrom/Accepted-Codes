// Problem: E. Relearn through Review
// Contest: Codeforces - The 2024 ICPC Kunming Invitational Contest
// URL: https://codeforces.com/gym/105386/problem/E
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

struct ST {
    #define lg2(n) (63 - __builtin_clzll((long long)(n)))
    int n;
    vector<vector<int>> st;
    ST (int n, vector<int> &a): n(n) {
        int layers = lg2(n) + 2;
        st.assign(layers, vector<int>(n, 0));
        for (int i = 0; i < n; i++) st[0][i] = a[i];

        for (int j = 1; j < layers; j++) {
            for (int i = 0; i + (1ll << j) - 1ll < n; i++) {
                st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1ll << (j - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int k = lg2(r - l + 1);
        return gcd(st[k][l], st[k][r - (1ll << k) + 1]);
    }
};

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n-1);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n-1;i++) b[i]=abs(a[i+1]-a[i]);
	ST st1(n,a);
	ST st2(n-1,b);
	int ans=st1.query(0,n-1);
	for(int l=0;l<n;l++) {
		int K=a[n-1];
		set<int> R;
		while (1) {
			int lo=l,hi=n-1,res=-1;
			while (lo <= hi) {
				int mid=lo+hi>>1;
				if (st1.query(mid,n-1) > K) hi=mid-1;
				else lo=mid+1,res=mid;
			}
			if (res == -1 or !R.empty() and R.find(res) != R.end()) break;
			R.insert(res);
			if (res == 0) break;
			K=st1.query(res,n-1)-1;
		}
		
		for(auto r : R) {
			// cout<<"l:"<<l<<" r:"<<r<<endl;
			int GCD=a[l]+k;
			if (l != 0) GCD=gcd(GCD,st1.query(0,l-1));
			if (r != n-1) GCD=gcd(GCD,st1.query(r+1,n-1));
			if (l != n-1 and l != r) GCD=gcd(GCD,st2.query(l,r-1));
			
			ans=max(ans,GCD);
		}
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









