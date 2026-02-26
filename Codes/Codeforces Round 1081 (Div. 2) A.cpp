// Problem: A. String Rotation Game
// Contest: Codeforces - Codeforces Round 1081 (Div. 2)
// URL: https://codeforces.com/contest/2192/problem/A
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
	string s;
	cin>>s;
	int cnt=0;
	int ok=0;
	for(int i=0;i<n;i++) {
		if (s[i] != s[(i-1+n)%n]) cnt++;
		else ok=1;
	}
	cout<<cnt+ok<<"\n";
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







