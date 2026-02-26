// Problem: 时不时使使用玉米加农炮掩饰害羞的邻座艾莉同学
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/H
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector a(n,vector<int>(m,0));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	
	auto calc=[&](int x,int y) -> int {
		int res=0;
		for(int i=x-2;i<=x+2;i++) {
			for(int j=y-2;j<=y+2;j++) {
				if (i < 0 or i >= n or j < 0 or j >= m) continue;
				if (abs(x-i)+abs(y-j) > 2) continue;
				res+=a[i][j];
			}
		}
		return res;
	};
	
	int ans=0,x1=0,y1=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			int res=calc(i,j);
			if (res > ans) x1=i,y1=j,ans=res;
		}
	}
	
	while (q--) {
		int x,y,w;
		cin>>x>>y>>w;
		x--,y--;
		a[x][y]+=w;
		for(int i=x-2;i<=x+2;i++) {
			for(int j=y-2;j<=y+2;j++) {
				if (i < 0 or i >= n or j < 0 or j >= m) continue;
				if (abs(x-i)+abs(y-j) > 2) continue;
				int res=calc(i,j);
				if (res > ans) x1=i,y1=j,ans=res;
			}
		}
		cout<<x1+1<<" "<<y1+1<<"\n";
	}
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







