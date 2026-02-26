// Problem: A. Same Difference
// Contest: Codeforces - Codeforces Round 1064 (Div. 2)
// URL: https://codeforces.com/contest/2166/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<n;i++) {
		ans-= s[i] == s[n-1];
	}
	cout<<ans+n<<"\n";
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







