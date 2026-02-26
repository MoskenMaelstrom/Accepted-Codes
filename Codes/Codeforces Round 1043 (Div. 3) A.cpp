// Problem: A. Homework
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/0
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
	int n,m;
	string s1,s2,s3;
	cin>>n>>s1>>m>>s2>>s3;
	
	deque<char> ans;
	for(int i=0;i<n;i++) ans.push_back(s1[i]);
	int p1=0,p2=0;
	for(int i=0;i<m;i++) {
		if (s3[i] == 'V') ans.push_front(s2[i]);
		else ans.push_back(s2[i]);
	}
	
	for(auto e1 : ans) cout<<e1;
	cout<<'\n';
	
	
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









