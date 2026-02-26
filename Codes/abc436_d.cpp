// Problem: D - Teleport Maze
// Contest: AtCoder - AtCoder Beginner Contest 436
// URL: https://atcoder.jp/contests/abc436/tasks/abc436_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector g(n,vector<char>(m));
	vector vec(26,vector<array<int,2>>(0));
	vector ans(n,vector<int>(m,inf));
	vector<bool> mark(26);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>g[i][j];
			if (g[i][j] >= 'a' and g[i][j] <= 'z') vec[g[i][j]-'a'].push_back({i,j});
		}	
	}
	
	queue<array<int,2>> q;
	q.push({0,0});
	ans[0][0]=0;
	while (!q.empty()) {
		auto [x,y]=q.front();
		q.pop();
		if (x == n-1 and y == m-1) {
			cout<<ans[x][y];
			return;
		}
		
		int id=g[x][y]-'a';
		if (g[x][y] >= 'a' and g[x][y] <= 'z' and !mark[id]) {
			mark[id]=1;
			for(auto [nx,ny] : vec[id]) {
				if (ans[nx][ny] <= ans[x][y]+1) continue;
				q.push({nx,ny});
				ans[nx][ny]=ans[x][y]+1;
			}
		}
		
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or g[nx][ny] == '#' or ans[nx][ny] <= ans[x][y]+1) continue;
			q.push({nx,ny});
			ans[nx][ny]=ans[x][y]+1;
		}
	}
	cout<<"-1";
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







