// Problem: P1470 [USACO2.3] 最长前缀 Longest Prefix
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1470
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;


vector<int> Next(string s) {
	int m=s.size();
	vector<int> next(m+1);
	next[0]=-1;
	next[1]=0;
	int i=2,cur=0;
	while (i < m+1) {
		if (s[i-1] == s[cur]) next[i++]=++cur;
		else if (cur > 0) cur=next[cur];
		else next[i++]=0;
	}
	return next;
}



void solve()
{
	vector<string> s;
	while (1) 
	{
		string sn;
		cin>>sn;
		if (sn == ".") break;
		s.push_back(sn);
	}
	string x;
	string s1;
	while (cin>>x) s1+=x;
	cin>>s1;
	int n=s1.size();
	int m=s.size();
	vector mark(n,vector<bool>(m));
	
	auto KMP=[&](string s1,string s2,int id) -> void {
		int n=s1.size();
		int m=s2.size();
		auto next=Next(s2);
		int x=0,y=0;
		while (x < n) {
			if (s1[x] == s2[y]) {
				x++;
				y++;
			}
			else if (y == 0) x++;
			else y=next[y];
			
			if (y == m) {
				mark[x-1][id]=1;
			}
		}
	};
	
	
	for(int i=0;i<m;i++) {
		KMP(s1,s[i],i);
	}
	
	vector<bool> f(n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (i-s[j].size()+1 >= 0) {
				if (mark[i][j] and i-s[j].size()+1 == 0) f[i]=1;
				else if (mark[i][j] and f[i-s[j].size()]) f[i]=1;
			}
		}
	}
	
	int ans=-1;
	for(int i=0;i<n;i++) {
		if (f[i]) ans=i;
	}
	cout<<ans+1;
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









