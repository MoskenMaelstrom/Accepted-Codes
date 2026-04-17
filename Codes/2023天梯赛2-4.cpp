#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		for(int j=0;j<m;j++) a[i][j]=s[j]-'0';
	}
	
	int k=1;
	vector vis(n,vector<int>(m));
	auto dfs=[&](auto&& self,int x,int y) -> void {
		if (vis[x][y]) return;
		vis[x][y]=k;
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or !a[nx][ny]) continue;
			self(self,nx,ny);
		}
	};
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (a[i][j] != 0) dfs(dfs,i,j);
			k++;
		}
	}
	
	set<int> st1;
	set<int> st2;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (a[i][j] >= 1 and vis[i][j]) st1.insert(vis[i][j]);
			if (a[i][j] > 1 and vis[i][j]) st2.insert(vis[i][j]);
		}
	}
	cout<<st1.size()<<" "<<st2.size();
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







