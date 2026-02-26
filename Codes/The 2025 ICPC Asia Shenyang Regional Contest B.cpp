#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	vector g(n,vector<int>(m));
	vector<int> tong(n*m+1);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>g[i][j];
			tong[g[i][j]]++;
		}
	}
	sort(tong.begin()+1,tong.end(),greater<int>());
	int ans=0;
	for(int i=1;i<=m*n;i++) {
		ans+=min(tong[i]*a,tong[i]*(i-1)*b+tong[0]*b);
	}
	
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







