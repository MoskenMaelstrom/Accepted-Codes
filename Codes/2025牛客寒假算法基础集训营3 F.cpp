#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if (n <= a+b+c and a+b+c <= 2*n) cout<<"Yes\n";
	else cout<<"No\n";
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









