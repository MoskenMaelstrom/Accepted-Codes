// Problem: C. Shifted MEX
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/C
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
	ranges::sort(a);
	a.erase(unique(a.begin(),a.end()),a.end());
	n=a.size();
	int ans=0,cur=0;
	for(int i=0;i<n;i++) {
		if (i != n-1 and a[i]+1 == a[i+1]) cur++;
		else ans=max(ans,cur),cur=0;
	}
	cout<<max(ans,cur)+1<<"\n";
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







