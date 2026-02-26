// Problem: E. Product Queries
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	a.erase(unique(a.begin(),a.end()),a.end());
	
	vector<int> ans(n+1,inf);
	for(int i=0;i<a.size();i++) ans[a[i]]=1;
	for(int i=1;i<=n;i++) {
		for(int j=1;i*j<=n;j++) {
			if (ans[i] != inf and ans[j] != inf) ans[i*j]=min(ans[i*j],ans[i]+ans[j]);
		}
	}
	for(int i=1;i<=n;i++) {
		if (ans[i] == inf) cout<<"-1 ";
		else cout<<ans[i]<<" ";
	}
	cout<<"\n";
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







