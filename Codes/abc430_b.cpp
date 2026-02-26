// Problem: B - Count Subgrid
// Contest: AtCoder - AtCoder Beginner Contest 430
// URL: https://atcoder.jp/contests/abc430/tasks/abc430_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<char>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}
	
	vector<vector<vector<char>>> vec;
	function<bool(vector<vector<char>>)> flag=[&](vector<vector<char>> c) {
		bool ok=1;
		for(auto cur : vec) {
			if (cur == c) ok=0;
		}
		return ok;
	};
	
	for(int i=0;i<n-m+1;i++) {
		for(int j=0;j<n-m+1;j++) {
			vector b(m,vector<char>(m));
			for(int x=i;x<i+m;x++) {
				for(int y=j;y<j+m;y++) {
					b[x-i][y-j]=a[x][y];
				}
			}
			if (flag(b)) {
				vec.push_back(b);
			}
		}
	}
	cout<<vec.size();
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







