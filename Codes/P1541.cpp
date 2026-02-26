// Problem: P1541 [NOIP 2010 提高组] 乌龟棋
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1541
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

int dp[41][41][41][41];
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	vector<int> cnt(5);
	for(auto &e1 : a) cin>>e1;
	for(auto &e1 : b) {
		cin>>e1;
		cnt[e1]++;
	}
	
	dp[0][0][0][0]=a[0];//一张都不出说明就在原点
	for(int i1=0;i1<=cnt[1];i1++) {
		for(int i2=0;i2<=cnt[2];i2++) {
			for(int i3=0;i3<=cnt[3];i3++) {
				for(int i4=0;i4<=cnt[4];i4++) {
					int len=i1+2*i2+3*i3+4*i4;
					if (i1 != 0) dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1-1][i2][i3][i4]+a[len]);
					if (i2 != 0) dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1][i2-1][i3][i4]+a[len]);
					if (i3 != 0) dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1][i2][i3-1][i4]+a[len]);
					if (i4 != 0) dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1][i2][i3][i4-1]+a[len]);
				}
			}
		}
	}
	cout<<dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
	
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









