// Problem: C. Trapped in the Witch's Labyrinth
// Contest: Codeforces - Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2034/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y)
{
	
}
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<string> > a(n+1,vector<string>(m+1));
	vector<vector<int> > mark(n+1,vector<int>(m+1));
	memset(mark.begin(),0,sizeof(mark));	//没走过标记为0;死路标记为2
	rep(i,n) rep(j,m) cin>>a[i][j];
	rep(i,n) rep(j,m) {						//先找出已有的死路
		
	}
	rep(i,n) rep(j,m){						//把所有?处理为方向
		if (a[i][j] == '?') 
		{
			rep(k,4) {
				int x=dx[k]+i;
				int y=dy[k]+j;
				if (x<1 or x>n or y<0 or y>m) continue;
			}
		}
	}
}
signed main()
{
	int t;
	cin>>t;
	while (t--) solve();
}


