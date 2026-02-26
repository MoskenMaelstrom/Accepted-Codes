// Problem: G - 数列离散化
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/G
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) {cin>>a[i][0];a[i][1]=i;}
	vector<int> rank(n);
	map<int,int> mp;
	
	ranges::sort(a);
	int r=0;
	for(int i=0;i<n;i++) {
		if (mp.count(a[i][0]) == 0) {
			rank[a[i][1]]=++r;
			mp[a[i][0]]=1;
		}
		else rank[a[i][1]]=r;
	}
	
	for(auto e1 : rank) cout<<e1<<" ";
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









