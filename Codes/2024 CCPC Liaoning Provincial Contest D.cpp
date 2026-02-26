#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n+1);
	for(int i=1;i<=n;i++) {
		cin>>a[i][0]>>a[i][1];
	}
	
	auto dis=[&](int x1,int y1,int x2,int y2) -> double {
		double dx=abs(x1-x2);
		double dy=abs(y1-y2);
		return sqrt(dx*dx+dy*dy);
	};
	
	vector<double> d(n+1);
	vector<double> dp(n+1);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			d[j]=max(d[j],dis(a[i][0],a[i][1],a[j][0],a[j][1]));
		}
		double mx=0;
		for(int j=i;j>=1;j--) {
			mx=max(mx,d[j]);
			dp[i]=max(dp[i],dp[j-1]+mx);
		}
	}
	printf("%.12f",dp[n]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









