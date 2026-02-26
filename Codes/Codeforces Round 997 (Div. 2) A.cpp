#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,m;
	int x,y;
	cin>>n>>m;
	cin>>x>>y;
	int ans=4*m;
	for(int i=2;i<=n;i++) {
		cin>>x>>y;
		x=m-x;
		y=m-y;
		ans+=4*m-(x+y)*2;
	}
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