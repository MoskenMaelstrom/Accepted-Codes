// Problem: A. Operations with Inversions
// Contest: Codeforces - Codeforces Round 1070 (Div. 2)
// URL: https://codeforces.com/contest/2176/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> mark(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if (a[j] < a[i]) mark[j]=1;
		}
	}
	
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (mark[i] == 1) cnt++;
	}
	cout<<cnt<<'\n';
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







