// Problem: Lazy Shuffling
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133877/L
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<array<int,2>> edge;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if (a[i] > a[j]) edge.push_back({a[i],a[j]});
		}
	}
	if (edge.empty()) {
		int ans=1;
		for(int i=1;i<=n;i++) {
			(ans*=i)%=p;
		}
		cout<<ans<<"\n";
		return;
	}
	
	vector<int> pre(n);
	for(auto e : edge) {
		auto [u,v]=e;
		u--,v--;
		pre[v]|=1<<u;
	}
	vector<int> dp(1<<n);
	dp[0]=1;
	for(int i=0;i<(1<<n);i++) {
		if (dp[i] == 0) continue;
		for(int u=0;u<n;u++) {
			if ((i&(1<<u)) == 0 and (pre[u]&i) == pre[u]) {
				(dp[i|(1<<u)]+=dp[i])%=p;
			}
		}
	}
	
	cout<<dp[(1<<n)-1]*2%p<<"\n";
}

signed main()	
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







