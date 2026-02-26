#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++) {
		int a1=max(a[i],a[i+1]);
		int a2=min(a[i],a[i+1]);
		if (a1 < a2*2) {cout<<"YES\n";return;}
	}
	cout<<"NO\n";
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