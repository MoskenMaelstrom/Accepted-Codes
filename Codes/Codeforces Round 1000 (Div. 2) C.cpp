// Problem: C. Remove Exactly Two
// Contest: Codeforces - Codeforces Round 1000 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2063/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int maxn;
int n;
vector<int> cnt;
vector<vector<int>> adj;
multiset<array<int,2>> st;
int ans;

void work(int num)
{
	st.erase({cnt[num],num});
	st.insert({0,num});
	for(auto ele : adj[num]) {
		st.erase({cnt[ele],ele});
		st.insert({cnt[ele]-1,ele});
	}
	ans=max(ans,(*(--st.end()))[0]+maxn-1);
	
	
	st.erase({0,num});
	st.insert({cnt[num],num});
	for(auto ele : adj[num]) {
		st.erase({cnt[ele]-1,ele});
		st.insert({cnt[ele],ele});
	}
}

void solve()
{
	ans=0;
	cin>>n;
	adj.assign(n,vector<int>(0));
	cnt.assign(n,0);
	st.clear();
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cnt[u]++;
		cnt[v]++;
	}
		 
	for(int i=0;i<n;i++) st.insert({cnt[i],i});
	maxn=*max_element(cnt.begin(),cnt.end());
	for(int i=0;i<n;i++) {
		if (cnt[i] == maxn) work(i);
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









