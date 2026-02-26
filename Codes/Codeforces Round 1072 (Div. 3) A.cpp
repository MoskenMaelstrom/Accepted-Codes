// Problem: A. Social Experiment
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	if (n <= 3) cout<<n<<"\n";
	else if (n%2 == 0) cout<<"0\n";
	else cout<<"1\n";
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







