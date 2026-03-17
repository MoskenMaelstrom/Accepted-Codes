// Problem: B. Modulo Sum
// Contest: Codeforces - Codeforces Round 319 (Div. 2)
// URL: https://codeforces.com/problemset/problem/577/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	if (n >= m) cout<<"YES";
	else {
		vector<bool> dp(m);
		for(int i=1;i<=n;i++) {
			vector<bool> ndp(m);
			ndp[a[i]%m]=1;
			for(int j=0;j<m;j++) {
				if (dp[j]) ndp[(j+a[i])%m]=1;
			}
			for(int j=0;j<m;j++) if (ndp[j]) dp[j]=1;
		}
		if (dp[0]) cout<<"YES";
		else cout<<"NO";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







