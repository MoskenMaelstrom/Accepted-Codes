#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<vector<int>> a;
	map< int,map<int,int> > mp;
	while (q--)
	{
		int opt,x,y;
		cin>>opt>>x>>y;
		if (opt == 1) {
			int k;
			cin>>k;
			mp[x][y]=k;
		} else {
			cout<<mp[x][y]<<endl;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









