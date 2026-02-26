// Problem: T - Looped Rope
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/T
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
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
	int ok=1;
	for(int x=0;x<n;x++) {
		for(int y=0;y<m;y++) {
			if (a[x][y] == '.') continue;
			int cnt=0;
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m or a[nx][ny] == '.') continue;
				cnt++;
			}
			if (cnt != 2 and cnt != 4) ok=0;
		}
	}
	if (ok) cout<<"Yes";
	else cout<<"No";
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









