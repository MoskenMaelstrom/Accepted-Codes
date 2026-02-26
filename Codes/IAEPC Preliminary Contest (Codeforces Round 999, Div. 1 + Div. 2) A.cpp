#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int ans=0;
	bool flag=0;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i]%2 == 0) flag=1;
	}
	for(int i=0;i<n;i++) if (a[i]%2 == 1) ans++;
	if (flag) cout<<ans+1<<endl;
	else cout<<ans-1<<endl;
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









