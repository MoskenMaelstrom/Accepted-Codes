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
		for(int j=0;j<m;j++) {
			a[i][j]='.';
		}
	}

	for(int i=0;i<n;i++) a[i][0]='#';
	for(int i=0;i<n;i++) a[i][m-1]='#';
	for(int j=0;j<m;j++) a[0][j]='#';
	for(int j=0;j<m;j++) a[n-1][j]='#';

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout<<a[i][j];
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







