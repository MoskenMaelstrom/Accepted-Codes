// Problem: P2957 [USACO09OCT] Barn Echoes G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2957
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

int KMP(string s1,string s2) {
	int n=s1.size();
	int m=s2.size();
	auto next=Next(s2);
	int x=0,y=0;
	while (x < n and y < m) {
		if (s1[x] == s2[y]) {
			x++;
			y++;
		}
		else if (y == 0) x++;
		else y=next[y];
	}
	
	return y;
}

void solve()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<max(KMP(s1,s2),KMP(s2,s1));
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









