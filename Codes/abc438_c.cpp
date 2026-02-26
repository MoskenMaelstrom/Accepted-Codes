// Problem: C - 1D puyopuyo
// Contest: AtCoder - AtCoder Beginner Contest 438
// URL: https://atcoder.jp/contests/abc438/tasks/abc438_c
// Memory Limit: 1024 MB
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
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		a.push_back(num);
		while (a.size() >= 4 and a[a.size()-1] == a[a.size()-2] and a[a.size()-2] == a[a.size()-3] and a[a.size()-3] == a[a.size()-4]) {
			a.pop_back();
			a.pop_back();
			a.pop_back();
			a.pop_back();
		}
	}
	while (a.size() >= 4 and a[a.size()-1] == a[a.size()-2] and a[a.size()-2] == a[a.size()-3] and a[a.size()-3] == a[a.size()-4]) {
		a.pop_back();
		a.pop_back();
		a.pop_back();
		a.pop_back();
	}
	cout<<a.size();
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







