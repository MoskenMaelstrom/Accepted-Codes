#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,ans=0;
	cin>>n>>k;
	vector<int> a(n+5,0);
	
	int pos=1;
	for(int i=k;i<=n;i+=k) a[i]=pos++;
	for(int i=1;i<=n;i++) {
		if (a[i] != 0) continue;
		a[i]=pos++;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
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