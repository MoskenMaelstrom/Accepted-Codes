// Problem: D. 黄金替罪羊
// Contest: Codeforces - 第十三届重庆市大学生程序设计竞赛
// URL: https://codeforces.com/gym/105887/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=100;
const int p=998244353;
int dp[N][N][N];
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=" "+s;
	for(int i=0;i<=n;i++) {
		if (i == n/2) continue;
		dp[1][i][i]=1;
	}
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			if (j == n/2) continue;
			for(int k=0;k<=n;k++) {
				for(int del=0;del<=1;del++) {
          	    	for(int add=0;add<=1;add++) {
          	      		if (del == 0 and s[i] == 'R') continue;
            			if (del == 1 and s[i] == 'L') continue;
            			if (add == 0 and s[i+n] == 'R') continue;
                		if (add == 1 and s[i+n] == 'L') continue;
                		int nj=j+add-del;
                		int nk=k-del;
                		if (nk < 0 or nk > n or nj < 0 or nj > n or nj == n/2) continue;
                		(dp[i+1][nj][nk]+=dp[i][j][k])%=p;
          	      	}
				}
			}
		}
	}
	
	int ans=0;
	for(int j=0;j<=n;j++) {
		if (j != n/2) (ans+=dp[n+1][j][0])%=p;
	}
	cout<<ans;
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







