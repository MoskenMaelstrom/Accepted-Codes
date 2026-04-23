// Problem: G. Snake Move
// Contest: Codeforces - The 2023 ICPC Asia Hangzhou Regional Contest (The 2nd Universal Cup. Stage 22: Hangzhou)
// URL: https://codeforces.com/gym/104976/problem/G
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
const int N=1e7;
vector<array<int,2>> T[N];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<array<int,2>> p(k+1);
	for(int i=1;i<=k;i++) cin>>p[i][0]>>p[i][1];
	vector vec(n+1,vector<int>(m+1));
	
	for(int i=1;i<=k;i++) {
		auto [x,y]=p[i];
		vec[x][y]=i;
	}
	
	for(int i=1;i<=n;i++) {
		string s;
		cin>>s;
		for(int j=1;j<=m;j++) {
			if (s[j-1] == '#') vec[i][j]=-1;
		}
	}
	
	vector dis(n+1,vector<int>(m+1,inf));
	dis[p[1][0]][p[1][1]]=0;
	T[0].push_back({p[1][0],p[1][1]});
	u64 sum=0;
	for(int i=0;i<N;i++) {
		for(auto [x,y] : T[i]) {
			if (dis[x][y] > i) continue;
			sum+=(u64)i*i;
			for(int d=0;d<4;d++) {
				int nx=x+dx[d];
				int ny=y+dy[d];
				if (nx <= 0 or nx > n or ny <= 0 or ny > m or vec[nx][ny] == -1) continue;
				int cur;
				if (vec[nx][ny] > 0 and k-i-1 >= vec[nx][ny]) cur=k-vec[nx][ny]+1;
				else cur=i+1;
				if (cur < dis[nx][ny]) {
					dis[nx][ny]=cur;
					T[cur].push_back({nx,ny});
				}
			}
		}
	}
	cout<<sum;
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







