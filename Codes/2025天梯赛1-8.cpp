#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
// #define int long long
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	priority_queue<array<int,3>> que;
	vector a(n,vector<int>(m));
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			que.push({a[i][j],i,j});
		}
	}
	
	vector<bool> row(n,1),col(m,1);
	while (1) {
		auto [val,x,y]=que.top();
		que.pop();
		if (row[x] and col[y]) {
			row[x]=0;
			col[y]=0;
			k--;
		}
		if (k == 0) break;
	}
	
	
	for(int i=0;i<n;i++) {
		if (!row[i]) continue;
		int ok=1;
		for(int j=0;j<m;j++) {
			if (!col[j]) continue;
			if (ok) cout<<a[i][j];
			else cout<<" "<<a[i][j];
			ok=0;
		}
		cout<<"\n";
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









