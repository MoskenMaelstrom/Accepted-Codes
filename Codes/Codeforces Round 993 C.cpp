#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int m,a,b,c;
	cin>>m>>a>>b>>c;
	
	int ans=0;
	int resta,restb;
	if (a>m) {ans+=m;resta=0;}
	else {ans+=a;resta=m-a;}
	if (b>m) {ans+=m;restb=0;}
	else {ans+=b;restb=m-b;}
	int rest=resta+restb;
	if (c>rest) ans+=rest;
	else ans+=c;
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