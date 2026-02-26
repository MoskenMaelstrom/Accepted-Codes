// Problem: A. Sleeping Through Classes
// Contest: Codeforces - Codeforces Round 1068 (Div. 2)
// URL: https://codeforces.com/contest/2173/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int cnt=0;
	int p=-1;
	for(int i=0;i<n;i++) {
		if (s[i] == '1') p=max(p,i+k);
		else if (i > p) cnt++;
	}
	cout<<cnt<<"\n";
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







