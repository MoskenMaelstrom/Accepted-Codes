#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int x,y,z,a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	cout<<max(x*a,max(y*b,z*c))<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









