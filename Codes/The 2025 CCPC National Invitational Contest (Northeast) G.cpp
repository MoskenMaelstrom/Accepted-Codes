// Problem: G. 加边
// Contest: Codeforces - The 2025 CCPC National Invitational Contest (Northeast), The 19th Northeast Collegiate Programming Contest
// URL: https://codeforces.com/gym/105924/problem/G
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
	vector<int> deg(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		deg[u]++;
		deg[v]++;
	}
	vector<int> vec;
	for(int i=0;i<n;i++) {
		if (deg[i]&1) vec.push_back(i);
	}
	
	n=vec.size();
	cout<<n/2<<"\n";
	for(int i=0;i<n;i+=2) {
		cout<<vec[i]+1<<" "<<vec[i+1]+1<<"\n";
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







