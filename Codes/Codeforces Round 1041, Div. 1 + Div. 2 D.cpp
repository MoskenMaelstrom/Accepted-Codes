// Problem: D. Root was Built by Love, Broken by Destiny
// Contest: Codeforces - Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2127/D
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

const int p=1e9+7;
const int N=2e5+5;
vector<int> jc(N);

void solve()
{
	int n,m;
	cin>>n>>m;
	
	vector adj(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if (n != m+1) {cout<<"0\n";return;}
	for(int i=0;i<n;i++) {
		int cnt=0;
		for(auto e1 : adj[i]) {
			if (adj[e1].size() >= 2) cnt++;
		}
		if (cnt > 2) {cout<<"0\n";return;}
	}
	
	vector<int> pos;//du >= 2
	for(int i=0;i<n;i++) {
		if (adj[i].size() >= 2) pos.push_back(i);
	}
	
	int ans=2;
	for(int i=0;i<n;i++) {
		int cnt=0;
		for(auto e1 : adj[i]) {
			if (adj[e1].size() == 1) cnt++;
		}
		ans*=jc[cnt];
		ans%=p;
	}
	if (pos.size() > 1) ans*=2;
	cout<<ans%p<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	jc[0]=1;
	for(int i=1;i<N;i++) {
		jc[i]=jc[i-1]*i;
		jc[i]%=p;
	}
	
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









