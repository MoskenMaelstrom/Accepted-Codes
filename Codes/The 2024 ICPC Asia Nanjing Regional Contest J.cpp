// Problem: J. Social Media
// Contest: Codeforces - The 2024 ICPC Asia Nanjing Regional Contest (The 3rd Universal Cup. Stage 16: Nanjing)
// URL: https://codeforces.com/gym/105484/problem/J
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	
	unordered_map<int,int> edge0;
	map<array<int,2>,int> edge1;
	set<int> st;
	for(int i=0;i<n;i++) {
		int u;
		cin>>u;
		st.insert(u);
	}
	
	int ans=0;
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		if (st.contains(u) and st.contains(v)) ans++;
		else if (st.contains(u) and !st.contains(v)) edge0[v]++;
		else if (!st.contains(u) and st.contains(v)) edge0[u]++;
		else if (u == v) edge0[u]++;
		else {
			if (edge1.count({u,v})) edge1[{u,v}]++;
			else edge1[{v,u}]++;
		}
	}
	
	int res=0;
	vector<int> vec;
	for(auto [v,w] : edge0) {
		vec.push_back(w);
	}
	ranges::sort(vec,greater<int>());
	if (vec.size() >= 2) {
		res=vec[0]+vec[1];
	}
	else if (vec.size() == 1){
		res+=vec[0];
	}
	
	for(auto [edge,w] : edge1) {
		auto [u,v]=edge;
		res=max(res,w+edge0[u]+edge0[v]);
	}
	
	cout<<ans+res<<"\n";
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







