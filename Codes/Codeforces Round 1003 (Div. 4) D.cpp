// Problem: D. Skibidus and Sigma
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/contest/2065/problem/D
// Memory Limit: 256 MB
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
	vector<int> b;
	int ans=0;
	for(int i=0;i<n;i++) {
		int sum=0;
		for(int j=0;j<m;j++) {
			int num;
			cin>>num;
			ans+=num*(m-j);
			sum+=num;
		}
		b.push_back(sum);
	}
	ranges::sort(b);
	for(int i=0;i<n;i++) {
		ans+=b[i]*i*m;
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









