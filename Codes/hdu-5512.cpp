// Problem:  Pagodas
// Contest: Virtual Judge - HDU
// URL: https://vjudge.net/problem/HDU-5512
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
int num=1;
void solve()
{
	int n,a,b;
	cin>>n>>a>>b;
	int d=gcd(a,b);
	cout<<"Case #"<<num++;
	if (n/d%2 == 0) cout<<": Iaka"<<endl;
	else cout<<": Yuwgna"<<endl;
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