#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int a,b;
	cin>>a>>b;
	int ans=inf;
	auto dfs=[&](auto&& self,int x,int y,int k) {
		if (k >= ans) return;
		if (x == 0 or y == 0) ans=k;
		int g=gcd(x,y);
		self(self,x-g,y,k+1);
		self(self,x,y-g,k+1);
	};

	dfs(dfs,a,b,0);
	cout<<ans+1<<"\n";
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





