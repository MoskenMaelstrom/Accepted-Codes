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
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];

	int ans=1;
	auto calc=[&](int xx,int yy) -> void {
		vector<array<int,2>> vec;
		for(int i=0;i<n;i++) {
			auto [x,y]=a[i];
			int nx=x*yy-y*xx;
			int ny=x*xx+y*yy;
			if (nx >= 0 and ny >= 0) vec.push_back({nx,ny});
		}
		int m=vec.size();
		ranges::sort(vec);
		vector<int> dp(m);
		for(int i=0;i<m;i++) dp[i]=1;
		for(int i=0;i<m;i++) {
			for(int j=i+1;j<m;j++) {
				if (vec[i][1] > vec[j][1]) continue;
				dp[j]=max(dp[j],dp[i]+1);
			}
			ans=max(ans,dp[i]);
		}
	};

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (i == j) continue;
			auto [x1,y1]=a[i];
			auto [x2,y2]=a[j];
			calc(x1-x2,y1-y2);
			calc(y1-y2,x2-x1);
		}
	}
	cout<<ans;
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







