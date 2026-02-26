// Problem: E. Dominating Point
// Contest: Codeforces - The 2023 ICPC Asia Xian Regional Contest (The 3rd Universal Cup. Stage 9: Xian)
// URL: https://codeforces.com/gym/105471/problem/E
// Memory Limit: 256 MB
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
	vector adj(n,vector<int>(0));
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		for(int j=0;j<n;j++) if (s[j] == '0' and j != i) adj[i].push_back(j);
	}
	int a1=-1,a2=-1,a3=-1;
	for(int i=0;i<n;i++) {
		if (a1 == -1 or adj[i].size() < adj[a1].size()) a1=i;
	}
	if (a1 != -1)
	for(auto v : adj[a1]) {
		if (a2 == -1 or adj[v].size() < adj[a2].size()) a2=v;
	}
	if (a2 != -1)
	for(auto v : adj[a2]) {
		if (a3 == -1 or adj[v].size() < adj[a3].size()) a3=v;
	}
	
	if (a1 == -1 or a2 == -1 or a3 == -1) cout<<"NOT FOUND";
	else cout<<a1+1<<" "<<a2+1<<" "<<a3+1;
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









