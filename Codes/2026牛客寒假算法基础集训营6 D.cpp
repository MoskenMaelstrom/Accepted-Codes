// Problem: 小L的扩展
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
const int inf=1e18;
void solve()
{
	int n,m,len1,len2;
	cin>>n>>m>>len1>>len2;
	vector mark(n,vector<int>(m));
	vector dist(n,vector<int>(m,inf));
	vector<array<int,2>> a(len1);
	for(int i=0;i<len1;i++) {
		cin>>a[i][0]>>a[i][1];
		a[i][0]--;
		a[i][1]--;
	}
	for(int i=0;i<len2;i++) {	
		int x,y;
		cin>>x>>y;
		x--,y--;
		cin>>mark[x][y];
	}
	priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
	for(auto [x,y] : a) pq.push({0,x,y});
	
	int ans=0;
	while (!pq.empty()) {
		auto [t,x,y]=pq.top();
		pq.pop();
		if (t > dist[x][y]) continue;
		ans=max(ans,t);
		
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx == n or ny < 0 or ny == m) continue;
			int cur=t+1;
			if (mark[nx][ny] > 0) cur=max(cur,mark[nx][ny]);
			if (cur < dist[nx][ny]) {
				dist[nx][ny]=cur;
				pq.push({cur,nx,ny});
			}
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







