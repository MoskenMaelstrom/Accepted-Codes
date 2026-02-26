// Problem: D - Snaky Walk
// Contest: AtCoder - AtCoder Beginner Contest 387
// URL: https://atcoder.jp/contests/abc387/tasks/abc387_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

const int inf=1e18;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void solve()
{
	int n,m;
	cin>>n>>m;
	int tx,ty;
	int sx,sy;
	vector a(n,vector<char>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if (a[i][j] == 'G') tx=i,ty=j;
			if (a[i][j] == 'S') sx=i,sy=j;
		}
	}
	
	vector cnt(n,vector<array<int,2>>(m,{inf,inf}));
	queue<array<int,4>> q;
	q.push({sx,sy,0,0});
	q.push({sx,sy,0,1});
	while (!q.empty()) {
		auto [x,y,step,mask]=q.front();
		q.pop();
		if (cnt[x][y][mask] <= step) continue; 
		cnt[x][y][mask]=step;
		if (a[x][y] == 'G') break;
		
		if (mask == 0) {
			for(int i=0;i<2;i++) {
				int cx=x+dx[i];
				int cy=y+dy[i];
				if (cx < 0 or cx >= n or cy < 0 or cy >= m or a[cx][cy] == '#') continue;
				q.push({cx,cy,step+1,mask^1});
			}
		}
		else {
			for(int i=2;i<4;i++) {
				int cx=x+dx[i];
				int cy=y+dy[i];
				if (cx < 0 or cx >= n or cy < 0 or cy >= m or a[cx][cy] == '#') continue;
				q.push({cx,cy,step+1,mask^1});
			}
		}
	};
	
	if (min(cnt[tx][ty][0],cnt[tx][ty][1]) == inf) cout<<"-1";
	else cout<<min(cnt[tx][ty][0],cnt[tx][ty][1]);
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







