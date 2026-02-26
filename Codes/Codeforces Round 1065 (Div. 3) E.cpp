// Problem: E. Anisphia Wynn Palettia and Good Permutations
// Contest: Codeforces - Codeforces Round 1065 (Div. 3)
// URL: https://codeforces.com/contest/2171/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(3,vector<int>(0));
	for(int i=1;i<=n;i++) {
		if (i%2 == 0) a[0].push_back(i);
		else if (i%3 == 0) a[1].push_back(i);
		else a[2].push_back(i);
	}
	while (a[0].size() >= 2 and a[2].size() >= 1) {
		cout<<a[2].back()<<" ";
		a[2].pop_back();
		cout<<a[0].back()<<" ";
		a[0].pop_back();
		cout<<a[0].back()<<" ";
		a[0].pop_back();
	}
	while (a[1].size() >= 2 and a[2].size() >= 1) {
		cout<<a[2].back()<<" ";
		a[2].pop_back();
		cout<<a[1].back()<<" ";
		a[1].pop_back();
		cout<<a[1].back()<<" ";
		a[1].pop_back();
	}
	while (!a[0].empty()) {
		cout<<a[0].back()<<" ";
		a[0].pop_back();
	}
	while (!a[1].empty()) {
		cout<<a[1].back()<<" ";
		a[1].pop_back();
	}
	while (!a[2].empty()) {
		cout<<a[2].back()<<" ";
		a[2].pop_back();
	}
	cout<<"\n";
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







