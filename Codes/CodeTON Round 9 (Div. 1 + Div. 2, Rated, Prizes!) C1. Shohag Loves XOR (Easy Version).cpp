#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	int x,m,y,ans=0;
	cin>>x>>m;
	for(int i=1;i<=min(2*x,m);i++){
		y=i;
		int t=x^y;
		if (t != 0 and (x%t == 0 or y%t == 0)) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}