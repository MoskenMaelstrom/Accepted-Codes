#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int a[200005];
	rep(i,n) cin>>a[i];
	int sum1=0,sum2=0;
	int s1=(n+1)/2,s2=n/2;
	for(int i=0;i<n;i+=2) sum1+=a[i];
	for(int i=1;i<n;i+=2) sum2+=a[i];
	if (sum1/s1 == sum2/s2 and sum1%s1 == 0 and sum2%s2 == 0) cout<<"YES\n";
	else cout<<"NO\n";
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