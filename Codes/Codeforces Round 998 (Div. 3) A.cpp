#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int a,b,d,e;
	cin>>a>>b>>d>>e;
	int c1=a+b;
	int c2=d-b;
	int ans1=1;
	int ans2=1;
	if (b+c1 == d) ans1++;
	if (c1+d == e) ans1++;
	
	if (a+b == c2) ans2++;
	if (c2+d == e) ans2++;
	cout<<max(ans1,ans2)<<endl;
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