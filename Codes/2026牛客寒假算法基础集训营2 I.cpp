// Problem: 01回文
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/I
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<char>(m));
	int c0=0,c1=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if (a[i][j] == '1') c1++;
			else c0++;
		}
	}
	
	if (c0 == 1) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if (a[i][j] == '1') cout<<"Y";
				else cout<<"N";
			}
			cout<<"\n";
		}
	}
	else if (c1 == 1) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if (a[i][j] == '0') cout<<"Y";
				else cout<<"N";
			}
			cout<<"\n";
		}
	}
	else {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cout<<"Y";
			}
			cout<<"\n";
		}
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







