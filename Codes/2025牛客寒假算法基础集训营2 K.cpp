// Problem: 可以分开吗？
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95334/K
// Memory Limit: 2048 MB
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


int n,m,cnt;
vector<vector<char>> a;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<array<int,2>> vec;
void dfs(int x,int y)
{
	a[x][y]='2';
	for(int i=0;i<4;i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
		if (a[nx][ny] == '2' or a[nx][ny] == '3') continue;
		if (a[nx][ny] == '0') {a[nx][ny]='3';cnt++;vec.push_back({nx,ny});}
		if (a[nx][ny] == '1') dfs(nx,ny);
	}
}

void solve()
{
	set<int> st;
	
	cin>>n>>m;
	a.assign(n,vector<char>(m));
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cnt=0;
			if (a[i][j] == '1') {
				dfs(i,j);
				for(auto [e1,e2] : vec) a[e1][e2]='0';
				vec.clear();
			}
			if (cnt != 0) st.insert(cnt);
		}
	}
	if (st.empty()) cout<<"0\n";
	else cout<<*st.begin()<<endl;
	 
	
	// for(int i=0;i<n;i++) {
		// for(int j=0;j<m;j++) {
			// cout<<a[i][j]<<" \n"[j == m-1];
		// }
	// }
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









