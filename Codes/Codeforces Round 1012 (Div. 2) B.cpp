// Problem: B. Pushing Balls
// Contest: Codeforces - Codeforces Round 1012 (Div. 2)
// URL: https://codeforces.com/contest/2090/problem/B
// Memory Limit: 512 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<char>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	
	vector mark(n,vector<bool>(m,0));
	
	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			if (a[i][j] == '1') {
				if (a[i][j-1] == '1') mark[i][j]=1;
				else break;
			}
		}
	}
	for(int j=1;j<m;j++) {
		for(int i=1;i<n;i++) {
			if (a[i][j] == '1') {
				if (a[i-1][j] == '1') mark[i][j]=1;
				else break;
			}
		}
	}
	
	
	
	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			if (a[i][j] == '1' and mark[i][j] == 0) {cout<<"NO\n";return;}
		} 
	}
	cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









