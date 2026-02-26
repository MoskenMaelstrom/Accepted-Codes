// Problem: C. Those Who Are With Us
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	
	int maxn=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			maxn=max(maxn,a[i][j]);
		}
	}
	
	int cnt=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (a[i][j] == maxn) cnt++;
		}
	}
	
	vector b=a;
	
	if (cnt <= 2) cout<<maxn-1<<"\n";
	else {	
		int x1,y1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if (a[i][j] == maxn) x1=i,y1=j;
			}
		}
		
		for(int i=0;i<n;i++) a[i][y1]--;
		bool ok=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if (a[i][j] == maxn) {
					for(int j1=0;j1<m;j1++) a[i][j1]--;
					for(int ii=0;ii<n;ii++) {
						for(int jj=0;jj<m;jj++) {
							if (a[ii][jj] == maxn) goto st1;
						}
					}
					cout<<maxn-1<<"\n";return;
				}
			}
		}
		
		st1:
		for(int j=0;j<m;j++) b[x1][j]--;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if (b[i][j] == maxn) {
					for(int i1=0;i1<n;i1++) b[i1][j]--;
					for(int ii=0;ii<n;ii++) {
						for(int jj=0;jj<m;jj++) {
							if (b[ii][jj] == maxn) {cout<<maxn<<"\n";return;}
						}
					}
					cout<<maxn-1<<"\n";return;
				}
			}
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









