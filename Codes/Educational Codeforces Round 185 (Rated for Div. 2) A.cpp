// Problem: A. Maximum Neighborhood
// Contest: Codeforces - Educational Codeforces Round 185 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2170/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void solve()
{
	int n;
	cin>>n;
	vector a(n,vector<int>(n));
	int cnt=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			a[i][j]=++cnt;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			int cost=a[i][j];
			for(int k=0;k<4;k++) {
				int x=dx[k]+i;
				int y=dy[k]+j;
				if (x < 0 or x >= n or y < 0 or y >= n) continue;
				cost+=a[x][y];
			}
			ans=max(cost,ans);
		}
	}
	cout<<ans<<"\n";
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







