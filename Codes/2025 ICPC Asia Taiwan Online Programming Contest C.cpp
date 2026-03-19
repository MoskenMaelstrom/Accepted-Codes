// Problem: C. One-Way Abyss
// Contest: Codeforces - 2025 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/106084/problem/C
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> ans(n+1);
	vector<int> ed(n+1);
	ranges::iota(ed,0);
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		ans[ed[u]]+=w;
		ans[ed[v]]+=w;
		int p1=ed[u],p2=ed[v];
		ed[v]=p1;
		ed[u]=p2;
	}
	cout<<*ranges::max_element(ans)<<"\n";
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







