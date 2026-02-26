// Problem: C. Mex in the Grid
// Contest: Codeforces - Codeforces Round 1024 (Div. 2)
// URL: https://codeforces.com/contest/2102/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void solve()
{
	int n;
	cin>>n;
	
	vector a(n,vector<int>(n,-1));
	int cnt=n*n-1,k=0;
	
	int x=0,y=0;
	while(cnt >= 0) {
		a[x][y]=cnt--;
		int nx=x+dx[k];
		int ny=y+dy[k];
		if (nx == -1 or nx == n or ny == -1 or ny == n or a[nx][ny] != -1) {
			k=(k+1)%4;
			nx=x+dx[k];
			ny=y+dy[k];
		}
		x=nx;
		y=ny;
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<a[i][j]<<" \n"[j == n-1];
		}
	}
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









