// Problem: B. OIE Excursion
// Contest: Codeforces - Codeforces Round 1093 (Div. 2)
// URL: https://codeforces.com/contest/2220/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int maxn=1,cur=1;
	for(int i=1;i<n;i++) {
		if (a[i-1] == a[i]) cur++,maxn=max(maxn,cur);
		else cur=1;
	}
	if (maxn >= m) cout<<"NO\n";
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







