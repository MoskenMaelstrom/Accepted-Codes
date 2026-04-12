// Problem: K. 微信小游戏
// Contest: Codeforces - The 2025 CCPC National Invitational Contest (Northeast), The 19th Northeast Collegiate Programming Contest
// URL: https://codeforces.com/gym/105924/problem/K
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

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
	
	vector<int> c(m+1);
	int ans=0;
	for(int i=1;i<=m;i++) {
		for(int j=0;j<m;j++) {
			int k=0,cnt=0;
			while (k < n and a[k][j] == i) {
				k++;
				cnt++;
			}
			c[i]=max(c[i],cnt);
		}
		ans+=n-c[i];
	}
	cout<<ans<<"\n";
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







