// Problem: D. Deductive Snooker Scoring
// Contest: Codeforces - The 2025 ICPC Asia Chengdu Regional Contest (The 4rd Universal Cup. Stage 4: Grand Prix of Chengdu)
// URL: https://codeforces.com/gym/106161/problem/D
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

map<array<int,4>,string> mp;
set<array<int,5>> vis;
string s;
void dfs(int a,int b,int n,int p,int sta) {
	if (s.size() > 100) return;
	if (vis.count({a,b,n,p,sta})) return;
	vis.insert({a,b,n,p,sta});
	if (!mp.count({a,b,n,p})) mp[{a,b,n,p}]=s;
	if (n == 0) return;
	
	if (n > 6) {
		s+="/";
		dfs(a,b,n,p^1,1);
		s.pop_back();
		
		if (sta == 1) {
			s+="1";
			if (p == 0) dfs(a+1,b,n-1,p,2);
			if (p == 1) dfs(a,b+1,n-1,p,2);
			s.pop_back();
		}
		if (sta == 2) {
			for(int i=2;i<=7;i++) {
				s+=to_string(i);
				if (p == 0) dfs(a+i,b,n,p,1);
				if (p == 1) dfs(a,b+i,n,p,1);
				s.pop_back();
			}
		}
	}
	else if (n == 6 and sta == 2) {
		s+="/";
		dfs(a,b,n,p^1,1);
		s.pop_back();
		
		for(int i=2;i<=7;i++) {
			s+=to_string(i);
			if (p == 0) dfs(a+i,b,n,p,1);
			if (p == 1) dfs(a,b+i,n,p,1);
			s.pop_back();
		}
	}
	else {
		s+="/";
		dfs(a,b,n,p^1,1);
		s.pop_back();
		
		s+=to_string(8-n);
		if (p == 0) dfs(a+8-n,b,n-1,p,1);
		if (p == 1) dfs(a,b+8-n,n-1,p,1);
		s.pop_back();
	}
}

void solve()
{
	int a,b,n,p;
	cin>>a>>b>>n>>p;
	if (mp.count({a,b,n,p})) cout<<mp[{a,b,n,p}]<<"\n";
	else cout<<"NA\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	dfs(0,0,21,0,1);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







