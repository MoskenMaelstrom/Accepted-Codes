// Problem: E. Explosive Slabstones Rearrangement
// Contest: Codeforces - 2025 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/106084/problem/E
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector a(n,vector<int>(m));
	for(int i=1;i<=k;i++) {
		int x,y;
		cin>>x>>y;
		x--,y--;
		a[x][y]=i;
	}
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	x1--,y1--,x2--,y2--;
	bool f=1;
	int lo=1;
	for(int i=x1;i<=x2;i++) {
		for(int j=y1;j<=y2;j++) {
			if (a[i][j]) f=0;
			lo=max(lo,a[i][j]);
		}
	}
	if (f) {cout<<"0\n";return;}
	
	auto check=[&](int num) -> bool {
		vector vis(n,vector<bool>(m));
		int c0=0;
		function<void(int,int)> dfs=[&](int x,int y) {
			vis[x][y]=1;
			if (a[x][y] == 0) c0++;
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if (nx < 0 or nx > n-1 or ny < 0 or ny > m-1 or vis[nx][ny] or a[nx][ny] > num) continue;
				dfs(nx,ny);
			}
		};
		for(int i=x1;i<=x2;i++) {
			for(int j=y1;j<=y2;j++) {
				if (!vis[i][j]) dfs(i,j);
			}
		}
		
		return c0 >= (x2-x1+1)*(y2-y1+1);
	};
	
	int hi=k,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,hi=mid-1;
		else lo=mid+1;
	}
	cout<<res<<"\n";
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







