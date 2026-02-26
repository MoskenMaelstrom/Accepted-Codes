#include<bits/stdc++.h>
#define int long long
using namespace std;

const double inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,6>> vec(n);
	for(auto& [a,b,c,d,e,p] : vec) {
		cin>>a>>b>>c>>d>>e>>p;
	}
	ranges::reverse(vec);
	
	vector<array<double,4>> dp(m+1);
	for(auto& [a,b,c,d,e,p] : vec) {
		vector<array<double,4>> ndp(m+1,{-inf,-inf,-inf,-inf});
		double p1=(double)p/100;
		double p2=1-p1;
		
		for(int j=0;j<=m-b;j++) {
			ndp[j+b][0]=max(ndp[j+b][0],a+p1*dp[j][1]+p2*dp[j][2]);
			ndp[j+b][1]=max(ndp[j+b][1],a+p1*dp[j][1]+p2*dp[j][3]);
			ndp[j+b][2]=max(ndp[j+b][2],a+p1*dp[j][3]+p2*dp[j][2]);
			ndp[j+b][3]=max(ndp[j+b][3],a+p1*dp[j][3]+p2*dp[j][3]);
		}
		
		for(int j=0;j<=m-d-e;j++) {
			ndp[j+d+e][3]=max(ndp[j+d+e][3],c+dp[j][0]);
		}
		
		for(int j=0;j<=m-d;j++) {
			ndp[j+d][0]=max(ndp[j+d][0],c+p1*dp[j][1]+p2*dp[j][2]);
			ndp[j+d][1]=max(ndp[j+d][1],c+p1*dp[j][1]+p2*dp[j][3]);
			ndp[j+d][2]=max(ndp[j+d][2],c+p1*dp[j][3]+p2*dp[j][2]);
		}
		
		dp=ndp;
	}
	
	double ans=-inf;
	for(int j=0;j<=m;j++) {
		ans=max(ans,dp[j][0]);
	}
	if (ans < 0) cout<<"-1";
	else cout<<fixed<<setprecision(12)<<ans;
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







