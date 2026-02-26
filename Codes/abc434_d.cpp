// Problem: D - Clouds
// Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2025 (AtCoder Beginner Contest 434)
// URL: https://atcoder.jp/contests/abc434/tasks/abc434_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2000;
void solve()
{
	vector diff(N+10,vector<int>(N+10));
	vector c(N+10,vector<int>(N+10));
	int n;
	cin>>n;
	vector<array<int,4>> a(n);
	for(int i=0;i<n;i++) {
		int u,d,l,r;
		cin>>u>>d>>l>>r;
		a[i]={u,d,l,r};
		diff[u][l]++;
		diff[u][r+1]--;
		diff[d+1][l]--;
		diff[d+1][r+1]++;
	}
	int cnt=0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
			if (diff[i][j] == 0) cnt++;
			if (diff[i][j] == 1) c[i][j]=1;
		}
	}
	
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
		}
	}
	
	for(int i=0;i<n;i++) {
		auto [u,d,l,r]=a[i];
		cout<<cnt+c[d][r]-c[d][l-1]-c[u-1][r]+c[u-1][l-1]<<"\n";
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







