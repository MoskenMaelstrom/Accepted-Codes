#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++) {
			if (i*j != n) ans+=i*j;
		}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}