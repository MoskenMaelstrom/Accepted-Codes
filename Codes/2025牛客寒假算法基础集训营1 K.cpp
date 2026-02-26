// Problem: 硝基甲苯之魇
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/K
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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
	int n,ans=0;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ST st(n,a);
	map<int,vector<int>> mp;
	int nxor=0;
	vector<int> pre(n);
	for(int i=0;i<n;i++) {
		nxor^=a[i];
		pre[i]=nxor;
		mp[nxor].push_back(i);
	}
	
	for(int l=0;l<n-1;l++) {
		int k=a[l];
		int prer=l;
		while (1) {
			int lo=l,hi=n-1,res=-1;
			while (lo <= hi) {
				int mid=lo+hi>>1;
				if (st.query(l,mid) < k) hi=mid-1;
				else lo=mid+1,res=mid;
			}
			int r=res;
			// cout<<"l:"<<l<<" r:"<<r<<endl;
			int G=(st.query(l,r) ^ (l != 0 ? pre[l-1] : 0));
			if (prer == l) ans+=upper_bound(mp[G].begin(),mp[G].end(),r)-upper_bound(mp[G].begin(),mp[G].end(),prer);
			else ans+=upper_bound(mp[G].begin(),mp[G].end(),r)-lower_bound(mp[G].begin(),mp[G].end(),prer);
			if (r == n-1) break;
			k=st.query(l,r+1);
			prer=r+1;
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









