// Problem: F. Build XOR on a Segment
// Contest: Codeforces - Educational Codeforces Round 185 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2170/problem/F
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<vector<array<int,3>>> que(n);
	int q;
	cin>>q;
	for(int i=0;i<q;i++) {
		int l,r,x;
		cin>>l>>r>>x;
		l--,r--;
		que[r].push_back({l,x,i});
	}
	vector<int> ans(q);
	
	vector dp(12,vector<int>(1<<12,-1));
	for(int i=0;i<n;i++) {
		dp[0][a[i]]=i;
		for(int j=0;j<11;j++) {
			for(int k=0;k<1<<12;k++) {
				dp[j+1][k^a[i]]=max(dp[j+1][k^a[i]],dp[j][k]);
			}
		}
		for(auto [l,x,id] : que[i]) {
			int c=0;
			while (c < 12 and dp[c][x] < l) c++;
			if (c == 12) ans[id]=0;
			else ans[id]=c+1;
		}
	}
	for(auto e1 : ans) cout<<e1<<" ";
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







