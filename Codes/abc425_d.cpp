// Problem: D - Ulam-Warburton Automaton
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_d
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
int dy[]={0,0,1,-1};
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<char>(m));
	queue<array<int,2>> q;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if (a[i][j] == '#') q.push({i,j});
		}
	}
	
	auto check=[&](int x,int y) -> bool {
		if (x < 0 or x >= n or y < 0 or y >= m or a[x][y] == '#') return 0;
		int cnt=0;
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
			if (a[nx][ny] == '#') cnt++;
		}
		if (cnt == 1) return 1;
		return 0;
	};
	
	queue<array<int,2>> q0;
	vector<array<int,2>> tmp;
	while (!q.empty() or !q0.empty()) {
		while (!q.empty()) {
			auto [x,y]=q.front();
			q.pop();
			
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if (check(nx,ny)) {
					tmp.push_back({nx,ny});
					q0.push({nx,ny});
				}
			}
		}
		for(auto [x,y] : tmp) a[x][y]='#';
		tmp.clear();
		
		while (!q0.empty()) {
			auto [x,y]=q0.front();
			q0.pop();
			
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if (check(nx,ny)) {
					tmp.push_back({nx,ny});
					q.push({nx,ny});
				}
			}
		}
		for(auto [x,y] : tmp) a[x][y]='#';
		tmp.clear();
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (a[i][j] == '#') ans++;
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









