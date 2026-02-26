// Problem: P3842 [TJOI2007] 线段
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3842
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> L(n),R(n),len(n);
	for(int i=0;i<n;i++) {
		cin>>L[i]>>R[i];
		len[i]=R[i]-L[i];
	}
	
	vector<array<int,2>> dp(n);//dp[i][0]存走完i行且停留在L的最小步数
	dp[0][0]=R[0]+len[0]-1;
	dp[0][1]=R[0]-1;
	for(int i=1;i<n;i++) {
		dp[i][0]=min(  dp[i-1][0]+abs(R[i]-L[i-1])+len[i]+1, dp[i-1][1]+abs(R[i]-R[i-1])+len[i]+1  );
		dp[i][1]=min(  dp[i-1][0]+abs(L[i]-L[i-1])+len[i]+1, dp[i-1][1]+abs(L[i]-R[i-1])+len[i]+1  );
	}
	cout<<min(n-R[n-1]+dp[n-1][1],n-L[n-1]+dp[n-1][0]);
	
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









