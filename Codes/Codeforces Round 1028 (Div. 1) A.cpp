// Problem: A. Gellyfish and Flaming Peony
// Contest: Codeforces - Codeforces Round 1028 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2115/A
// Memory Limit: 512 MB
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
// #define int long long
using namespace std;

const int inf=1E9,N=5000;
int G[N+1][N+1];
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	int g=0;
	for(int i=1;i<=n;i++) g=gcd(a[i],g);
	int cnt=count(a.begin()+1,a.end(),g);
	
	if (cnt != 0) cout<<n-cnt<<"\n";
	else {
		vector dp(n+1,vector<int>(N+1,inf));//前i个数字，gcd为j至少要选几个数字
		for(int i=0;i<=n;i++) dp[i][0]=0;
		for(int i=1;i<=n;i++) { 
			for(int x=0;x<=N;x++) {
				int y=gcd(a[i],x);
                dp[i][x]=min(dp[i][x],dp[i-1][x]);
				dp[i][y]=min(dp[i][y],dp[i-1][x]+1);
			}
		}
		cout<<dp[n][g]+n-2<<"\n";
	}
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
