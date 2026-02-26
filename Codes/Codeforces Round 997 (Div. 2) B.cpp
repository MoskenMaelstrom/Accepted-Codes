#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector a(n+1,vector<char>(n+1));
	vector<int> ans(n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++) {
		int pos=1;
		for(int j=1;j<=n;j++) {
			if (j<i and a[i][j] == '1' or i<j and a[i][j] == '0') pos++;
		}
		ans[pos]=i;
	}
	
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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
