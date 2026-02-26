#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int inf=1e18;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<int>(m));
	int l,r;
	cin>>l>>r;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		for(int j=0;j<m;j++) {
			a[i][j]=s[j]-'0';
		}
	}
	
	vector dis(n,vector(m,vector<int>(2,inf)));
	queue<array<int,3>> q;
	dis[0][0][0]=0;
	q.push({0,0,0});//{x,y,mask}
	while (!q.empty()) {
		auto [x,y,mask]=q.front();
		q.pop();
		for(int i=0;i<8;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx<0 or nx>=n or ny<0 or ny>=m or a[nx][ny]==0) continue;
			if (dis[nx][ny][1-mask] > dis[x][y][mask]+1) {
				dis[nx][ny][1-mask]=dis[x][y][mask]+1;
				q.push({nx,ny,1-mask});
			}
		}
	}
	
	// for(int i=0;i<n;i++) {
		// for(int j=0;j<m;j++) {
			// int e1=dis[i][j][0];
			// if (e1 == inf) cout<<"i ";
			// else cout<<e1<<" ";
		// }
		// cout<<'\n';
	// }
	
	int ans=inf;
	int d0=dis[n-1][m-1][0];
	int d1=dis[n-1][m-1][1];
	if (d0 == inf and d1 == inf) ans=inf;
	else if (l != r) {
		ans=(min(d0,d1)+r-1)/r;
	}
	else {
		if (r%2 == 0) {
			if (d0 != inf) ans=(d0+r-1)/r;
		}
		else {
			if (d0 != inf and (d0%r == 0 or d0%r%2 == 1)) ans=min(ans,(d0+r-1)/r);
			else if (d0 != inf) ans=min(ans,(d0+r-1)/r+1);
			if (d1 != inf and (d1%r == 0 or d1%r%2 == 1)) ans=min(ans,(d1+r-1)/r);
			else if (d1 != inf) ans=min(ans,(d1+r-1)/r+1);
		}
	}
	
	if (ans == inf) cout<<"-1\n";
	else cout<<ans<<'\n';
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









