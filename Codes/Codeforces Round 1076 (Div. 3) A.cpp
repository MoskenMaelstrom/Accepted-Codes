// Problem: A. DBMB and the Array
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/A
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
	int n,s,x;
	cin>>n>>s>>x;
	int sum=0;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		sum+=num;
	}
	if (sum > s or (s-sum)%x) cout<<"NO\n";
	else cout<<"YES\n";
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







