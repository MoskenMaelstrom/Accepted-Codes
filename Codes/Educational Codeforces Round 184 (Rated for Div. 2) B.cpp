// Problem: B. Drifting Away
// Contest: Codeforces - Educational Codeforces Round 184 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2169/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	
	bool ok=1;
	for(int i=0;i<n-1;i++) {
		if (s[i] == '>' and s[i+1] == '*') ok=0;
		if (s[i] == '*' and s[i+1] == '<') ok=0;
		if (s[i] == '>' and s[i+1] == '<') ok=0;
	}
	
	for(int i=0;i<n-1;i++) {
		if (s[i] == '*' and s[i+1] == '*') ok=0;
	}
	
	if (ok == 0) cout<<"-1\n";
	else {
		int ans=0;
		int cnt=0;
		for(int i=0;i<n;i++) {
			if (s[i] == '<' or s[i] == '*') cnt++;
			if (s[i] == '>') break;
		}
		ans=max(ans,cnt);
		cnt=0;
		ranges::reverse(s);
		for(int i=0;i<n;i++) {
			if (s[i] == '>' or s[i] == '*') cnt++;
			if (s[i] == '<') break;
		}
		ans=max(ans,cnt);
		
		cout<<ans<<'\n';
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







