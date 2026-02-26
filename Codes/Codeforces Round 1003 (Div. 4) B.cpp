// Problem: B. Skibidus and Ohio
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/contest/2065/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length()-1;i++) {
		if (s[i]==s[i+1]) {cout<<1<<endl;return;}
	}
	cout<<s.length()<<endl;
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









