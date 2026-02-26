// Problem: D. Locked Out
// Contest: Codeforces - Pinely Round 5 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2161/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector vec(n,vector<int>(0));
	for(int i=0;i<n;i++) {
		a[i]--;
		vec[a[i]].push_back(i);
	}
	
	int ans=0;
	for(int i=0;i<n-1;i++) {
		for(int j=(int)vec[i].size()-1;j>=0;j--) {
			if (!vec[i+1].empty() and vec[i][j] < vec[i+1].back()) {
				ans++;
				vec[i+1].pop_back();
			}
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







