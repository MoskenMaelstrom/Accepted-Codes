#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int num;
	num=n%(a+b+c);
	if (num == 0) cout<<n/(a+b+c)*3;
	else if (num <= a) cout<<n/(a+b+c)*3+1;
	else if (num <= a+b) cout<<n/(a+b+c)*3+2;
	else if (num <= a+b+c) cout<<n/(a+b+c)*3+3;
	cout<<"\n";
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