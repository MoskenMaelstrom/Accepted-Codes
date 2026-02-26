// Problem: E - Sort Arrays
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Christmas (AtCoder Beginner Contest 437)
// URL: https://atcoder.jp/contests/abc437/tasks/abc437_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int N=3e5+1;

map<int,int> mp;
map<int,int> tree[N];
vector<int> vec[N];
int cnt=1;

void dfs(int u) {
	for(auto id : vec[u]) cout<<id<<" ";
	for(auto [w,v] : tree[u]) dfs(v);
}

void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		if (tree[mp[x]].count(y) == 0) tree[mp[x]][y]=cnt++;
		mp[i]=tree[mp[x]][y];
		vec[mp[i]].push_back(i);
	}
	dfs(0);
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







