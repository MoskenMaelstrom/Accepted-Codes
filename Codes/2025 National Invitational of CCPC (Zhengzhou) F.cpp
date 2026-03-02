// Problem: F. 幻形之路
// Contest: Codeforces - 2025 National Invitational of CCPC (Zhengzhou), 2025 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105941/problem/F
// Memory Limit: 2048 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<char>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	
	vector vis1(n,vector<int>(m));
	function<void(int,int)> dfs1=[&](int x,int y) {
		vis1[x][y]=1;
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or vis1[nx][ny]) continue;
			if (a[nx][ny] == '.') dfs1(nx,ny); 
		}
	};
	dfs1(0,0);
	
	vector vis2(n,vector<int>(m));
	function<void(int,int)> dfs2=[&](int x,int y) {
		vis2[x][y]=1;
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or vis2[nx][ny]) continue;
			if (a[nx][ny] == '.') dfs2(nx,ny);
		}
	};
	dfs2(n-1,m-1);
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (vis1[i][j] and vis2[i][j]) {cout<<0<<"\n";return;}
		}
	}
	
	vector dis(n,vector<int>(m));
	vector vis(n,vector<int>(m));
	queue<array<int,2>> q;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (vis1[i][j]) {
				q.push({i,j});
				dis[i][j]=0;
				vis[i][j]=1;
			}
		}
	}
	
	int ans=inf;
	while (!q.empty()) {
		auto [x,y]=q.front();
		q.pop();
		if (vis2[x][y]) ans=min(ans,dis[x][y]);
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or vis[nx][ny]) continue;
			vis[nx][ny]=1;
			dis[nx][ny]=dis[x][y]+1;
			q.push({nx,ny});
		}
	}
	cout<<max(ans-1,0ll)<<"\n";
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







