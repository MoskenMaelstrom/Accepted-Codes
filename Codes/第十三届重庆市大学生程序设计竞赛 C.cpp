// Problem: C. 区域划分
// Contest: Codeforces - 第十三届重庆市大学生程序设计竞赛
// URL: https://codeforces.com/gym/105887/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve()
{
	int n;
	cin>>n;
	int cnt=1;
	vector a(n,vector<int>(n));
	for(int x=0;x<=2*n-2;x++) {
		for(int i=0;i<n;i++) {
			int j=x-i;
			if (j >= n) continue;
			if (j < 0) break;
			a[i][j]=cnt;
			if (cnt == n) cnt=1;
			else cnt++;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	// vector<set<int>> vec(n+1);
	// for(int i=0;i<n;i++) {
		// for(int j=0;j<n;j++) {
			// for(int k=0;k<4;k++) {
				// int nx=i+dx[k];
				// int ny=j+dy[k];
				// if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
				// vec[a[i][j]].insert(a[nx][ny]);
			// }
		// }
	// }
	// for(int i=1;i<=n;i++) cout<<vec[i].size()<<"\n";
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







