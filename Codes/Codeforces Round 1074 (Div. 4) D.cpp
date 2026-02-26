// Problem: D. OutOfMemoryError
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/D
// Memory Limit: 256 MB
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
	int n,m,h;
	cin>>n>>m>>h;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<array<int,2>> vec;
	while (m--) {
		int id,v;
		cin>>id>>v;
		id--;
		vec.push_back({id,a[id]});
		a[id]+=v;
		if (a[id] > h) {
			while (!vec.empty()) {
				auto [i,val]=vec.back();
				vec.pop_back();
				a[i]=val;
			}
		}
	}
	
	for(auto e1 : a) cout<<e1<<" ";
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







