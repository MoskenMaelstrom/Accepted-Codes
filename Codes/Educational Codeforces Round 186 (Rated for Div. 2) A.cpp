// Problem: A. New Year String
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/A
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
	string s;
	cin>>s;
	
	int ok=0;
	for(int i=0;i<n-3;i++) {
		if (s[i] == '2' and s[i+1] == '0' and s[i+2] == '2' and s[i+3] == '6') {
			cout<<0<<"\n";
			return;
		}
		
		if (s[i] == '2' and s[i+1] == '0' and s[i+2] == '2' and s[i+3] == '5') ok=1;
	}
	
	cout<<ok<<"\n";
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







