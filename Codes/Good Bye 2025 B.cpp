// Problem: B. Impost or Sus
// Contest: Codeforces - Good Bye 2025
// URL: https://codeforces.com/contest/2178/problem/B
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
	string s;
	cin>>s;
	int n=s.size();
	int ans=0;
	if (s[0] == 'u') s[0]='s',ans++;
	if (s[n-1] == 'u') s[n-1]='s',ans++;
	for(int i=0;i<n-1;i++) {
		if (s[i] == 'u' and s[i+1] == 'u') s[i+1]='s',ans++;
	}
	cout<<ans<<"\n";
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







