#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k,p;
	cin>>n>>k>>p;
	k=abs(k);
	int m=(k+p-1)/p;
	if (m <= n) cout<<m<<endl;
	else cout<<-1<<endl;
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









