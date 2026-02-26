// Problem: F. Gravity Falls
// Contest: Codeforces - Codeforces Round 1050 (Div. 4)
// URL: https://codeforces.com/contest/2148/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	int n,maxk=0;
	cin>>n;
	vector a(n,vector<int>(0));
	for(int i=0;i<n;i++) {
		int k,num;
		cin>>k;
		maxk=max(maxk,k);
		for(int j=0;j<k;j++) {
			cin>>num;
			a[i].push_back(num);
		}
	}
	vector rol(maxk,vector<int>(0));
	for(int i=0;i<n;i++) {
		for(int j=0;j<a[i].size();j++) {
			rol[j].push_back(i);
		}
	}
	
	vector<int> rank(n,-1),best(maxk);
	for(int j=maxk-1;j>=0;j--) {
		vector<array<int,3>> vec;
		for(auto& i : rol[j]) {
			vec.push_back({a[i][j],rank[i],i});
		}
		ranges::sort(vec);
		best[j]=vec[0][2];
		int rk=0;
		for(auto& [cur,prerk,i] : vec) rank[i]=rk++;
	}
	// for(int i=0;i<maxk;i++) cout<<best[i]<<" ";
	// cout<<endl;
	
	int pos=0;
	vector<int> ans;
	while (pos < maxk) {
		int i=best[pos];
		int ed=a[i].size();
	
		for(int j=pos;j<ed;j++) ans.push_back(a[i][j]);
		pos=ed;
	}
	for(auto& e1 : ans) cout<<e1<<" ";
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









