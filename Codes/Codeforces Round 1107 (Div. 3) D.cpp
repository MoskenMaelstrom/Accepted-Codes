// Problem: D. An Alternative Way
// Contest: Codeforces - Codeforces Round 1107 (Div. 3)
// URL: https://codeforces.com/contest/2241/problem/D
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
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	int	sum=0;
	for(int i=0;i<n;i++) {
		sum+=b[i]-a[i];
		if (sum < 0) {cout<<"NO\n";return;}
	}
	
	cout<<"YES\n";
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







