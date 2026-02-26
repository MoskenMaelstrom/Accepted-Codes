// Problem: D. Monster Game
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/D
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
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	ranges::sort(a);
	int sum=0;
	int ans=0;
	for(int i=0;i<n;i++) {
		sum+=b[i];
		if (sum > n) break;
		ans=max(ans,a[n-sum]*(i+1));
	}
	cout<<ans<<"\n";
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







