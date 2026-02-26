// Problem: E - Wind Cleaning
// Contest: AtCoder - Panasonic Programming Contest 2025（AtCoder Beginner Contest 427）
// URL: https://atcoder.jp/contests/abc427/tasks/abc427_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<char>(m));
	vector<array<int,2>> p;
	int x1,y1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if (a[i][j] == 'T') x1=i,y1=j;
			if (a[i][j] == '#') p.push_back({i,j});
		}
	}
	
	int ans=-1;
	queue<pair<vector<array<int,2>>,int>> q;
	map<vector<array<int,2>>,bool> vis;
	q.push({p,0}); 
	while (!q.empty()) {
		auto [mask,step]=q.front();
	 	q.pop();
	 	if (mask.empty()) {ans=step;break;}
	 	
	 	for(int i=0;i<4;i++) {
	 		int ok=1;
		 	vector<array<int,2>> cur;
		 	for(auto [x,y] : mask) {
		 		int nx=x+dx[i];
		 		int ny=y+dy[i];
		 		if (nx == x1 and ny == y1) {ok=0;break;}
		 		if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
		 		cur.push_back({nx,ny});
		 	}
		 	if (ok == 0 or vis[cur]) continue;
		 	vis[cur]=1;
		 	q.push({cur,step+1});
	 	}
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









