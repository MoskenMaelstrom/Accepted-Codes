// Problem: C. Specialty String
// Contest: Codeforces - Codeforces Round 1084 (Div. 3)
// URL: https://codeforces.com/contest/2200/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<char> sta;
	for(int i=0;i<n;i++) {
		char c;
		cin>>c;
		if (!sta.empty() and sta.back() == c) sta.pop_back();
		else sta.push_back(c);
	}
	if (sta.empty()) cout<<"YES\n";
	else cout<<"NO\n";
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







