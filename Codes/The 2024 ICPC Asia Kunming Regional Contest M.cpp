#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n+1,vector<int>(m+1));
	cout<<"Yes\n";
	int cnt=1;
	for(int k=2;k<=n+m;k++) {
		for(int i=1,j=k-i;i<=n and j>=1;i++,j--) {
			if (j > m) continue;
			a[i][j]=cnt++;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
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







