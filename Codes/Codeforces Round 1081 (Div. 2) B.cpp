// Problem: B. Flipping Binary String
// Contest: Codeforces - Codeforces Round 1081 (Div. 2)
// URL: https://codeforces.com/contest/2192/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
	int c0=ranges::count(s,'0');
	int c1=ranges::count(s,'1');
	
	if (c0%2 != 1 and c1%2 != 0) cout<<"-1\n";
	else {
		if (c0%2 == 1) {
			cout<<c0<<"\n";
			for(int i=0;i<n;i++) {
				if (s[i] == '0') cout<<i+1<<" ";
			}
			if (c0 != 0) cout<<"\n";
		}
		else {
			cout<<c1<<"\n";
			for(int i=0;i<n;i++) {
				if (s[i] == '1') cout<<i+1<<" ";
			}
			if (c1 != 0) cout<<"\n";
		}
	}
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







