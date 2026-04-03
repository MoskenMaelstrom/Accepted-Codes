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
	vector vec(m,vector<int>(0));
	for(int i=0;i<n;i++) {
		int k;
		cin>>k;
		for(int j=0;j<k;j++) {
			int id;
			cin>>id;
			id--;
			vec[id].push_back(i);
		}
	}

	for(int i=0;i<m;i++) ranges::sort(vec[i]);
	int q;
	cin>>q;
	while (q--) {
		int x,y;
		cin>>x>>y;
		x--,y--;
		int cnt=0;
		for(int i=0;i<vec[x].size();i++) {
			if (!vec[y].empty() and ranges::binary_search(vec[y],vec[x][i])) {
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







