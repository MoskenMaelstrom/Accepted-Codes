// Problem: E2. Maple and Tree Beauty (Hard Version)
// Contest: Codeforces - Codeforces Round 1048 (Div. 2)
// URL: https://codeforces.com/contest/2139/problem/E2
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
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

const int inf=1e18;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> fa(n);
	for(int i=1;i<n;i++) {cin>>fa[i];fa[i]--;}
	
	vector adj(n,vector<int>(0));
	for(int i=1;i<n;i++) {
		adj[fa[i]].push_back(i);
	}
	
	vector<int> dep(n);
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto v : adj[u]) {
			dep[v]=dep[u]+1;
			q.push(v);
		}
	}
	
	int deep=inf;
	for(int i=0;i<n;i++) {
		if (adj[i].size() == 0) deep=min(deep,dep[i]);
	}
	
	int sum=0;
	vector<int> c(deep+1);//每层的节点数
	for(int i=0;i<n;i++) {
		if (dep[i] > deep) continue;
		c[dep[i]]++;
		sum++;
	}
	
	map<int,int> mp;//节点数:层数
	for(int i=0;i<=deep;i++) mp[c[i]]++;
	
	vector<array<int,2>> item;//{cost,val}
	for(auto [d,cnt] : mp) {
		for(int i=0;cnt-(1<<i) >= 0;i++) {
			item.push_back({d*(1<<i),d*(1<<i)});
			cnt-=(1<<i);
		}
		if (cnt != 0) item.push_back({d*cnt,d*cnt});
	}
		
	vector<int> dp(k+1);
	for(int i=0;i<item.size();i++) {
		for(int j=k;j-item[i][0]>=0;j--) {
			dp[j]=max(dp[j],dp[j-item[i][0]]+item[i][1]);
		}
	}
	if (sum-dp[k] <= n-k) cout<<deep+1<<"\n";
	else cout<<deep<<"\n";
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









