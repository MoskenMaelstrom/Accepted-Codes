#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<char>(m));
	int x1=0,y1=0;
	int x2=0,y2=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if (a[i][j] == 'S') x1=i,y1=j;
			if (a[i][j] == 'G') x2=i,y2=j;
		}
	}

	vector vis(n,vector<array<bool,4>>(m));
	vector pre(n,vector<array<int,4>>(m,{-1,-1,-1,-1}));
	queue<array<int,3>> q;
	q.push({x1,y1,0});
	int d=-1;
	while (!q.empty()) {
		auto [x,y,o]=q.front();
		q.pop();
		if (a[x][y] == '.' or a[x][y] == 'S') {
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m or a[nx][ny] == '#') continue;
				if (vis[nx][ny][i]) continue;
				vis[nx][ny][i]=1;
				pre[x][y][i]=o;
				if (a[nx][ny] == 'G') {d=i;break;}
				q.push({nx,ny,i});
			}
		}
		else if (a[x][y] == 'o') {
			int nx=x+dx[o];
			int ny=y+dy[o];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or a[nx][ny] == '#') continue;
			if (vis[nx][ny][o]) continue;
			vis[nx][ny][o]=1;
			pre[x][y][o]=o;
			if (a[nx][ny] == 'G') {d=o;break;}
			q.push({nx,ny,o});
		}
		else {
			for(int i=0;i<4;i++) {
				if (i == o) continue;
				int nx=x+dx[i];
				int ny=y+dy[i];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m or a[nx][ny] == '#') continue;
				if (vis[nx][ny][i]) continue;
				vis[nx][ny][i]=1;
				pre[x][y][i]=o;
				if (a[nx][ny] == 'G') {d=i;break;}
				q.push({nx,ny,i});
			}
		}
	}
	
	if (d == -1) {cout<<"No\n";return;}
	cout<<"Yes\n";
	string s;
	while (x1 != x2 or y1 != y2) {
		if (d == 0) s+="D";
		if (d == 1) s+="R";
		if (d == 2) s+="U";
		if (d == 3) s+="L";
		x2=x2+dx[(d+2)%4];
		y2=y2+dy[(d+2)%4];
		d=pre[x2][y2][d];
	}
	ranges::reverse(s);
	cout<<s;
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







