// Problem: E. Blackslex and Girls
// Contest: Codeforces - Codeforces Round 1071 (Div. 3)
// URL: https://codeforces.com/contest/2179/problem/E
// Memory Limit: 256 MB
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
	bool ok=1;
	int n,x,y;
	cin>>n>>x>>y;
	string s;
	cin>>s;
	vector<int> p(n);
	for(int i=0;i<n;i++) cin>>p[i];
	
	int n0=0,n1=0;
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (s[i] == '0') cnt++,n0+=p[i]/2+1;
		else n1+=p[i]/2+1;
	}
	
	if (accumulate(p.begin(),p.end(),0ll) > x+y) ok=0;
	if (x < n0) ok=0;
	if (y < n1) ok=0;
	if (cnt == n and x-n < y) ok=0;
	if (cnt == 0 and y-n < x) ok=0; 
	
	if (ok) cout<<"YES\n";
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







