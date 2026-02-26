// Problem: A. Final Verdict
// Contest: Codeforces - Codeforces Round 1008 (Div. 2)
// URL: https://mirror.codeforces.com/contest/2078/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int n,x;
	cin>>n>>x;
	int sum=0;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		sum+=num;
	}
	if (sum%x == 0 and sum/n == x) cout<<"YES\n";
	else cout<<"NO\n";
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









