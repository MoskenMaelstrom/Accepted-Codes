// Problem: Fastest Coverage Problem
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108302/J
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
// #define int long long
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int inf=1e9;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	vector dist(n,vector<int>(m,inf));
	queue<array<int,2>> q;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (a[i][j] == 1) {
				dist[i][j]=0;
				q.push({i,j});
			}
		}
	}
	
	if (q.empty()) {cout<<m/2+n/2;return;}
	
	while (!q.empty()) {
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m or dist[nx][ny] <= dist[x][y] + 1) continue;
			dist[nx][ny]=dist[x][y]+1;
			q.push({nx,ny});
		}
	}
	
	vector<array<int,2>> ok;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (a[i][j] == 0) ok.push_back({i,j});
		}
	}
	    
	auto check=[&](int mid) -> bool {
		int jial=-1e9,jiar=1e9,jianl=-1e9,jianr=1e9;
		for(int i=0;i<n;i++) {	
			for(int j=0;j<m;j++) {
				if (dist[i][j] > mid) {
					jial=max(jial,i+j-mid);
					jiar=min(jiar,i+j+mid);
					jianl=max(jianl,i-j-mid);
					jianr=min(jianr,i-j+mid);
				}
			}
		}
        if (jial == -1e9) return 1;
	    jial=max(jial,0);
	    jiar=min(jiar,n+m-2);
	    jianl=max(jianl,1-m);
	    jianr=min(jianr,n-1);
        if (jial > jiar or jianl > jianr) return 0;
        if (jial == jiar and jianl == jianr and jial%2 != jianl%2) return 0;
        return 1;
	};
	
	int lo=0,hi=2e5,res=-1;
	while (lo <= hi)
	{
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,hi=mid-1;
		else lo=mid+1;
	}
	cout<<res;
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









