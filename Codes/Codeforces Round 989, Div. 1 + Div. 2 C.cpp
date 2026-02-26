// Problem: C. Trapped in the Witch's Labyrinth
// Contest: Codeforces - Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2034/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

constexpr int dx[]={-1,1,0,0};
constexpr int dy[]={0,0,-1,1};
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
	
	vector b(n,vector<bool>(m));
	for(int j=0;j<m;j++) {
		if (a[0][j] == 'U') b[0][j]=1;
	}
	for(int j=0;j<m;j++) {
		if (a[n-1][j] == 'D') b[n-1][j]=1;
	}
	for(int i=0;i<n;i++) {
		if (a[i][0] == 'L') b[i][0]=1;
	}
	for(int i=0;i<n;i++) {
		if (a[i][m-1] == 'R') b[i][m-1]=1;
	}
	
	queue<array<int,2>> q;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (b[i][j]) q.push({i,j});
		}
	}
	
	vector mark(n,vector<int>(m));
	while (!q.empty()) {
		auto [x,y]=q.front();
		q.pop();
		mark[x][y]=1;
		
		for(int d=0;d<4;d++) {
			int nx=dx[d]+x;
			int ny=dy[d]+y;
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or mark[nx][ny]) continue;
			if (d == 0 and a[nx][ny] == 'D') {b[nx][ny]=1;q.push({nx,ny});}
			if (d == 1 and a[nx][ny] == 'U') {b[nx][ny]=1;q.push({nx,ny});}
			if (d == 2 and a[nx][ny] == 'R') {b[nx][ny]=1;q.push({nx,ny});}
			if (d == 3 and a[nx][ny] == 'L') {b[nx][ny]=1;q.push({nx,ny});}
		}
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (a[i][j] == '?') {
				int cnt=0;
				for(int d=0;d<4;d++) {
					int nx=dx[d]+i;
					int ny=dy[d]+j;
					if (nx < 0 or nx >= n or ny < 0 or ny >= m or b[nx][ny] == 1) cnt++;
				}
				if (cnt == 4) b[i][j]=1;
			}
		}
	}
	
	int cnt=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			// cout<<b[i][j]<<" \n"[j == m-1];
			if (b[i][j]) cnt++;
		}
	}
	
	cout<<n*m-cnt<<"\n";
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









