// Problem: B. Expensive Number
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	int cntq=0,cntp=0;
	int endi;
	for(int i=0;i<n;i++) if (s[i] != '0') endi=i;
	for(int i=0;i<endi;i++) if (s[i] == '0') cntq++;
	for(int i=endi+1;i<n;i++) if (s[i] == '0') cntp++;
	
	cout<<endi-cntq+cntp<<endl;
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









