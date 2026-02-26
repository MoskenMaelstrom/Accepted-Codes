#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++) {
		int A=min(a[i],a[i-1]);
		a[i]-=A;
		a[i-1]-=A;
	}
	for(int i=1;i<=n-1;i++) {
		if (a[i] > a[i+1]) {cout<<"NO\n";return;}
	}
	cout<<"YES\n";
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