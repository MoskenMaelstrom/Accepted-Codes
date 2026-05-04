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
	vector<array<int,3>> vec(n+1);
	for(int i=1;i<=n;i++) cin>>vec[i][1]>>vec[i][0]>>vec[i][2];
	
	sort(vec.begin()+1,vec.end());
	vector<double> dp(m+1);
	for(int i=1;i<=n;i++) {
		auto [v,p,w]=vec[i];
		for(int j=m;j>=w;j--) {
			dp[j]=max(dp[j],dp[j-w]*(1-(double)p/100)+(double)v*p/100);
		}
	}
	cout<<fixed<<setprecision(10)<<*ranges::max_element(dp)<<"\n";
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







