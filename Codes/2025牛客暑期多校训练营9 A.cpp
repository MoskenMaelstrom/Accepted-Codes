#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int inf=1e18;
vector<int> feb(60);
void solve()
{
	int n;
	cin>>n;
	vector<int> l(n+1),r(n+1),fa(n+1),deg(n+1);
	vector dp(n+1,vector<int>(40,inf));
	queue<int> q;
	for(int i=1;i<=n;i++) {
		cin>>l[i]>>r[i];
		if (l[i] > 0) fa[l[i]]=i,deg[i]++;
		if (r[i] > 0) fa[r[i]]=i,deg[i]++;
		if (deg[i] == 0) q.push(i);
	}
	
	while (!q.empty()) {
		int i=q.front();
		q.pop();
		deg[fa[i]]--;
		for(int h=0;h<40;h++) {
			if (h == 0) {
				int c1=0,c2=0;
				if (l[i] > 0) c1=dp[l[i]][0];
				if (r[i] > 0) c2=dp[r[i]][0];
				dp[i][h]=c1+c2+1;
			}
			else if (h == 1) {
				int c1=0,c2=0;
				if (l[i] > 0) c1=dp[l[i]][0];
				if (r[i] > 0) c2=dp[r[i]][0];
				dp[i][h]=c1+c2;
			}
			else {
				if (l[i] > 0 and r[i] > 0) {
					dp[i][h]=min({dp[l[i]][h-1]+dp[r[i]][h-1],dp[l[i]][h-2]+dp[r[i]][h-1],dp[l[i]][h-1]+dp[r[i]][h-2]});
				}
				if (l[i] == 0 and r[i] > 0) {
					dp[i][h]=min(dp[r[i]][h-1]+feb[h-2],dp[r[i]][h-2]+feb[h-1]);
				}
				if (l[i] > 0 and r[i] == 0) {
					dp[i][h]=min(dp[l[i]][h-1]+feb[h-2],dp[l[i]][h-2]+feb[h-1]);
				}
				if (l[i] == 0 and r[i] == 0) {
					dp[i][h]=feb[h-1]+feb[h-2];
				}
			}
		}
		if (deg[fa[i]] == 0) q.push(fa[i]);
	}
	
	int ans=inf;
	for(int i=0;i<40;i++) {
		ans=min(ans,dp[1][i]);
	}
	cout<<ans<<'\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	feb[0]=0;
	feb[1]=1;
	for(int i=2;i<60;i++) {
		feb[i]=feb[i-1]+feb[i-2]+1;
	}
	while (t--)
		solve();
	return 0;
}









