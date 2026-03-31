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
	vector a(n,vector<char>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) cin>>a[i][j];
	}

	int cnt=0;
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<m-1;j++) {
			if (a[i][j] == 'c' and a[i][j+1] == 'c' and a[i+1][j] == 'p' and a[i+1][j+1] == 'c') {
				cnt++;
			}
		}
	}

	cout<<cnt;
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







