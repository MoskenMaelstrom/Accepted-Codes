// Problem: C. Smilo and Minecraft
// Contest: Codeforces - Codeforces Round 1031 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2113/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

void solve()
{
	int n,m,k;
	int cnt=0;
	cin>>n>>m>>k;
	vector a(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
			if (a[i][j] == 'g') cnt++;
		}
	}
	
	vector pre(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			pre[i][j]=(a[i][j] == 'g')+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
		}
	}
	
	int ans=0;
	vector vec(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if (a[i][j] != '.') continue;
			int x1=i-(k-1);x1=max(1,x1);
			int y1=j-(k-1);y1=max(1,y1);
			int x2=i+(k-1);x2=min(n,x2);
			int y2=j+(k-1);y2=min(m,y2);
			
			ans=max(ans,cnt-(pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]));
		}
	}
	cout<<ans<<"\n";
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









