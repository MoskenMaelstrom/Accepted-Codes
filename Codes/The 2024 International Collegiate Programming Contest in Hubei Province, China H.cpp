#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> x(k),y(k),a(k);
	for(int i=0;i<k;i++) cin>>x[i]>>y[i]>>a[i];
	vector<int> masks;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			int mask=0;
			for(int v=0;v<k;v++) {
				if (abs(x[v]-i)+abs(y[v]-j) <= 1) mask|=1<<(2*v);
			}
			if (mask) masks.push_back(mask);
		}
	}
	ranges::sort(masks,greater<int>());
	vector<int> tmp;
	for(auto s : masks) {
		bool ok=1;
		for(auto t : tmp) {
			if ((s&t) == s) {
				ok=0;
				break;
			}
		}
		if (ok) tmp.push_back(s);
	}
	swap(masks,tmp);

	vector<int> dp(1<<(2*k),1e18);
	dp[0]=0;
	for(int s=1;s<(1<<(2*k));s++) {
		for(auto t : masks) {
			int nt=(t&s)|(t&(s>>1));
			dp[s]=min(dp[s],dp[s-nt]+1);
		}
	}

	int mask=0;
	for(int i=0;i<k;i++) {
		mask|=a[i]<<(2*i);
	}
	cout<<dp[mask]<<"\n";
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







