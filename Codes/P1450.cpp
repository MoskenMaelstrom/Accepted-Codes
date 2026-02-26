// Problem: P1450 [HAOI2008] 硬币购物
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1450
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

const int N=1e5;
void solve()
{
	vector<int> c(5);
	for(int i=1;i<=4;i++) cin>>c[i];
	int n;
	cin>>n;
	
	vector dp(N+1,vector<int>(5));
	for(int j=1;j<=4;j++) dp[0][j]=1;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=4;j++) {
			dp[i][j]+=dp[i][j-1];
			if (i >= c[j]) dp[i][j]+=dp[i-c[j]][j];
		}
	}
	
	for(int i=0;i<n;i++) {
		vector<int> d(5);
		for(int i=1;i<=4;i++) cin>>d[i];
		int s;
		cin>>s;
		
		int ans=dp[s][4];
		for(int i=1;i<=4;i++) {
			if (s-(d[i]+1)*c[i] >= 0) {
				ans-=dp[s-(d[i]+1)*c[i]][4];
			}
		}
		for(int i=1;i<=4;i++) {
			for(int j=i+1;j<=4;j++) {
				if (s-(d[i]+1)*c[i]-(d[j]+1)*c[j] >= 0) {
					ans+=dp[s-(d[i]+1)*c[i]-(d[j]+1)*c[j]][4];
				}
			}
		}
		for(int i=1;i<=4;i++) {
			for(int j=i+1;j<=4;j++) {
				for(int k=j+1;k<=4;k++) {
					if (s-(d[i]+1)*c[i]-(d[j]+1)*c[j]-(d[k]+1)*c[k] >= 0) {
						ans-=dp[s-(d[i]+1)*c[i]-(d[j]+1)*c[j]-(d[k]+1)*c[k]][4];
					}
				}
			}
		}
		if (s-(d[1]+1)*c[1]-(d[2]+1)*c[2]-(d[3]+1)*c[3]-(d[4]+1)*c[4] >= 0) {
			ans+=dp[s-(d[1]+1)*c[1]-(d[2]+1)*c[2]-(d[3]+1)*c[3]-(d[4]+1)*c[4]][4];
		}
		cout<<ans<<"\n";
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







