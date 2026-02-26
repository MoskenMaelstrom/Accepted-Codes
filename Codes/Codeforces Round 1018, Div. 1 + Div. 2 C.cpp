// Problem: C. Wonderful City
// Contest: Codeforces - Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2096/C
// Memory Limit: 256 MB
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
	int n;
	cin>>n;
	vector a(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}
	
	vector<int> c1(n),c2(n);
	for(int i=0;i<n;i++) cin>>c1[i];
	for(int i=0;i<n;i++) cin>>c2[i];
	
	//当前 != 前面
	auto check0=[&](int row) {
		for(int j=0;j<n;j++) {
			if (a[row][j] == a[row-1][j]) return 0;
		}
		return 1;
	};
	
	//当前 != 前面+1
	auto check1=[&](int row) {
		for(int j=0;j<n;j++) {
			if (a[row][j] == a[row-1][j]+1) return 0;
		}
		return 1;
	};
	
	//当前+1 != 前面
	auto check2=[&](int row) {
		for(int j=0;j<n;j++) {
			if (a[row][j]+1 == a[row-1][j]) return 0;
		}
		return 1;
	};
	
	vector<array<int,2>> dp(n,{inf,inf});
	dp[0][0]=0;
	dp[0][1]=c1[0];
	
	for(int i=1;i<n;i++) {
		if (check0(i)) dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if (check1(i)) dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if (check0(i)) dp[i][1]=min(dp[i][1],dp[i-1][1]+c1[i]);
		if (check2(i)) dp[i][1]=min(dp[i][1],dp[i-1][0]+c1[i]);
	}
	int ans=min(dp[n-1][0],dp[n-1][1]);
	
	
	//当前 != 前面
	auto check00=[&](int col) {
		for(int i=0;i<n;i++) {
			if (a[i][col] == a[i][col-1]) return 0;
		}
		return 1;
	};
	
	//当前 != 前面+1
	auto check11=[&](int col) {
		for(int i=0;i<n;i++) {
			if (a[i][col] == a[i][col-1]+1) return 0;
		}
		return 1;
	};
	
	//当前+1 != 前面
	auto check22=[&](int col) {
		for(int i=0;i<n;i++) {
			if (a[i][col]+1 == a[i][col-1]) return 0;
		}
		return 1;
	};
	
	dp.assign(n,{inf,inf});
	dp[0][0]=0;
	dp[0][1]=c2[0];
	for(int j=1;j<n;j++) {
		if (check00(j)) dp[j][0]=min(dp[j][0],dp[j-1][0]);
		if (check11(j)) dp[j][0]=min(dp[j][0],dp[j-1][1]);
		if (check00(j)) dp[j][1]=min(dp[j][1],dp[j-1][1]+c2[j]);
		if (check22(j)) dp[j][1]=min(dp[j][1],dp[j-1][0]+c2[j]);
	}
	ans+=min(dp[n-1][0],dp[n-1][1]);
	if (ans >= inf) cout<<"-1\n";
	else cout<<ans<<"\n";
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









