// Problem: D. Brand New Tatar TV Show
// Contest: Codeforces - Codeforces Round 1103 (Div. 3)
// URL: https://codeforces.com/contest/2236/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> c(n+1);
	for(int i=0;i<n;i++) c[a[i]]++;
	ranges::sort(a,greater<int>());
	a.push_back(0);
	
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (a[i] == a[i+1]) continue;
		if (cnt or cnt == 0 and c[a[i]]%2 == 0) {cout<<"YES\n";return;}
		cnt+=c[a[i]];
		if (a[i]-a[i+1] > k) cnt=0;
	}
	cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







