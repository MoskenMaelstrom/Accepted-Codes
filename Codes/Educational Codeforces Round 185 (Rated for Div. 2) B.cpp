// Problem: B. Addition on a Segment
// Contest: Codeforces - Educational Codeforces Round 185 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2170/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	int sum=0;
	cin>>n;
	vector<int> b(n);
	for(int i=0;i<n;i++) {
		cin>>b[i];
		sum+=b[i];
	}
	int cnt=ranges::count(b,0);
	cout<<min(sum+1-n,n-cnt)<<"\n";
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







