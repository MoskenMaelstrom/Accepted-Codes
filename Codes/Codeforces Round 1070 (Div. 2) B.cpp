// Problem: B. Optimal Shifts
// Contest: Codeforces - Codeforces Round 1070 (Div. 2)
// URL: https://codeforces.com/contest/2176/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0,c=0;
	for(int i=0;i<n;i++) {
		if (s[i] == '0') c++;
		else c=0;
		ans=max(ans,c);
	}
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (s[i] == '0') cnt++;
		else break;
	}
	for(int i=n-1;i>=0;i--) {
		if (s[i] == '0') cnt++;
		else break;
	}
	cout<<max(ans,cnt)<<"\n";
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







