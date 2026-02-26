// Problem: F. Maximum modulo equality
// Contest: Codeforces - Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2050/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

//1-based
struct ST {
    #define lg2(n) (63 - __builtin_clzll((long long)(n)))
    int n, B;
    vector<vector<int>> st;
    ST (int n, vector<int> &a): n(n) {
        B = lg2(n) + 2;
        st.assign(B, vector<int>(n + 5, 0));
        for (int i = 1; i <= n; i++) st[0][i] = a[i];
 
        for (int j = 1; j < B; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
 
    int query(int l, int r) {
        int k = lg2(r - l + 1);
        return gcd(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector<int> b(n+1);
	for(int i=1;i<=n;i++) {
		b[i]=abs(a[i]-a[i-1]);
	}
	
	ST st(n+1,b);
	
	while (q--) {
		int l,r;
		cin>>l>>r;
		if (l == r) cout<<"0 ";
		else cout<<st.query(l+1,r)<<" ";
	}
	cout<<"\n";
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









