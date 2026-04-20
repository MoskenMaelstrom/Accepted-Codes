// Problem: E - LRUD Moving
// Contest: AtCoder - Keysight Technologies Programming Contest（AtCoder Beginner Contest 454）
// URL: https://atcoder.jp/contests/abc454/tasks/abc454_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
string s1="LRUD";
void solve()
{
	int n,x1,y1;
	cin>>n>>x1>>y1;
	x1--,y1--;
	if (n%2 == 1 or (x1+y1)%2 == 0) {
		cout<<"No\n";
		return;
	}
	
	cout<<"Yes\n";
	string s;
	bool f=0;
	for(int j=0;j<n;j+=2) {
		if (j != y1 and j+1 != y1) {
			if (!f) {
				s+=string(n-1,'D');
				s+="R";
				s+=string(n-1,'U');
				s+="R";	
			}
			else {
				s+=string(n-1,'U');
				s+="R";	
				s+=string(n-1,'D');
				if (j == n-2) break;
				s+="R";
			}
		}
		else {
			f=1;
			vector vis(n,vector<int>(n,1));
			for(int i=0;i<n;i++) vis[i][j]=0;
			for(int i=0;i<n;i++) vis[i][j+1]=0;
			vis[x1][y1]=1;
			auto dfs=[&](auto&& self,int x,int y) -> void {
				vis[x][y]=1;
				for(int i=0;i<4;i++) {
					int nx=x+dx[i];
					int ny=y+dy[i];
					if (nx < 0 or nx >= n or ny < 0 or ny >= n or vis[nx][ny]) continue;
					s+=s1[i];
					self(self,nx,ny);
					return;
				}
			};
			dfs(dfs,0,j);
			if (j == n-2) break;
			s+="R";
		}
	}
	cout<<s<<"\n";
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







