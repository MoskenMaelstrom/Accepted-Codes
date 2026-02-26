#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,a,b;
	cin>>n>>a>>b;
	if (abs(a-b) % 2 == 1) cout<<"NO\n";
	else cout<<"Yes\n";
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