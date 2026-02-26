// Problem: E. Points Selection
// Contest: Codeforces - Educational Codeforces Round 184 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2169/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
	vector<int> x(n),y(n);
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<n;i++) cin>>y[i];
	for(int i=0;i<n;i++) cin>>c[i];
	
	vector<int> dp(16,-inf);
	dp[0]=0;
	for(int i=0;i<n;i++) {
		auto ndp=dp;
		for(int s=0;s<16;s++) {
			int cost=0;
			if (s&1) cost+=x[i];
			if (s&2) cost-=x[i];
			if (s&4) cost+=y[i];
			if (s&8) cost-=y[i];
			cost<<=1;
			cost-=c[i];
			for(int t=0;t<16;t++) {
				if ((s&t) != 0) continue;
				ndp[s|t]=max(ndp[s|t],dp[t]+cost);
			}
		}
		dp=ndp;
	}
	cout<<accumulate(c.begin(),c.end(),0ll)+dp[15]<<"\n";
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







