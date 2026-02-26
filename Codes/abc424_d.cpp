// Problem: D - 2x2 Erasing 2
// Contest: AtCoder - AtCoder Beginner Contest 424
// URL: https://atcoder.jp/contests/abc424/tasks/abc424_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<char>(m));
	vector<int> mask(n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if (a[i][j] == '#') mask[i]+=1<<(m-j-1);
		}
	}
	
	vector dp(n,vector<int>(1<<m,inf));
	for(int j=0;j<(1<<m);j++) {
		dp[0][j]=__builtin_popcountll(mask[0]^j);
	}
	
	for(int i=1;i<n;i++) {
		for(int b1=0;b1<(1<<m);b1++){
			for(int b2=0;b2<(1<<m);b2++) {
				if ((b1&b2)&((b1&b2)>>1)) continue;
				dp[i][b2]=min(dp[i][b2],dp[i-1][b1]+(int)__builtin_popcountll(mask[i]^b2));
			}
		}
	}
	
	int ans=inf;
	for(int b=0;b<(1<<m);b++) {
		ans=min(ans,dp[n-1][b]);
	}
	cout<<ans<<'\n';
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









