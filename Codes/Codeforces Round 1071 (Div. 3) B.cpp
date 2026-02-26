// Problem: B. Blackslex and Showering
// Contest: Codeforces - Codeforces Round 1071 (Div. 3)
// URL: https://codeforces.com/contest/2179/problem/B
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
	for(int i=0;i<n;i++) cin>>a[i];
	
	int sum=0;
	for(int i=1;i<n;i++) sum+=abs(a[i-1]-a[i]);
	int ans=sum;
	ans=min(ans,sum-abs(a[0]-a[1]));
	ans=min(ans,sum-abs(a[n-1]-a[n-2]));
	for(int i=1;i<n-1;i++) {
		ans=min(ans,sum-abs(a[i-1]-a[i])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]));
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







