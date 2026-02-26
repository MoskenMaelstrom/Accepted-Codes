// Problem: F. Blackslex and Another RGB Walking
// Contest: Codeforces - Codeforces Round 1071 (Div. 3)
// URL: https://codeforces.com/contest/2179/problem/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void agent()
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
	
	queue<int> q;
	q.push(0);
	vector<int> ans(n,-1);
	ans[0]=0;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto v : adj[u]) {
			if (ans[v] != -1) continue;
			ans[v]=(ans[u]+1)%3;
			q.push(v);
		}
	};
	for(auto e1 : ans) {
		if (e1 == 0) cout<<"r";
		else if (e1 == 1) cout<<"g";
		else cout<<"b";
	}
	cout<<"\n";
}

void solve()
{
	int q;
	cin>>q;
	while (q--) {
		int n;
		cin>>n;
		vector<int> vec(n);
		
		for(int i=0;i<n;i++) {
			char c;
			cin>>c;
			if (c == 'r') vec[i]=0;
			if (c == 'g') vec[i]=1;
			if (c == 'b') vec[i]=2;
		}
		
		set<int> st;
		for(auto e1 : vec) st.insert(e1);
		
		int c;
		if (st.size() == 1) c=*st.begin();
		else {
			int c1=*st.begin();
			int c2=*(++st.begin());
			if (c1 == 0 and c2 == 2) c=0;
			if (c1 == 0 and c2 == 1) c=1;
			if (c1 == 1 and c2 == 2) c=2;
		}
		
		for(int i=0;i<n;i++) {
			if (vec[i] == c) {cout<<i+1<<"\n";break;}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string opt;cin>>opt;
	int t;cin>>t;
	for(int i=0;i<t;i++) {
		if (opt[0] == 'f') agent();
		else solve();
	}
	return 0;
}







