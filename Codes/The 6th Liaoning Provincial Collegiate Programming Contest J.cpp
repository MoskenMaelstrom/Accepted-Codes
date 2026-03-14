// Problem: J. Just reseat!
// Contest: Codeforces - The 6th Liaoning Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106380/problem/J
// Memory Limit: 256 MB
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
	vector vec(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int i,x;
			cin>>i>>x;
			i--;
			vec[i].push_back(x);
		}
		else {
			int i1,j1,i2,j2;
			cin>>i1>>j1>>i2>>j2;
			i1--,j1--,i2--,j2--;
			swap(vec[i1][j1],vec[i2][j2]);
		}
	}
	for(int i=0;i<n;i++) {
		cout<<vec[i].size()<<" ";
		for(auto x : vec[i]) cout<<x<<" ";
		cout<<"\n";
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







