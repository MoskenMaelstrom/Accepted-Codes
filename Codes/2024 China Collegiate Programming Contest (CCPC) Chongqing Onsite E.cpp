// Problem: E. 合成大西瓜
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Chongqing Onsite
// URL: https://codeforces.com/gym/106030/problem/E
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	int v1=0,i1=0,v2=0,i2=0;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		if (num > v1) v2=v1,v1=num,i2=i1,i1=i;
		else if (num > v2) v2=num,i2=i;
	}
	
	vector<int> deg(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		deg[u-1]++;
		deg[v-1]++;
	}
	
	if (deg[i1] == 1) cout<<v2;
	else cout<<v1;
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







