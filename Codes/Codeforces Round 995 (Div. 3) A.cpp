#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
void solve()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) if (a[i]-b[i+1] > 0) ans+=a[i]-b[i+1];
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