#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans;
void dfs(int x)
{
	if (x<=3) return;
	ans*=2;
	dfs(x/4);
}
void solve()
{
	ans=1;
	int n;
	cin>>n;
	dfs(n);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}