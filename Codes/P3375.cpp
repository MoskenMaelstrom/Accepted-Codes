// Problem: P3375 【模板】KMP
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3375
// Memory Limit: 512 MB
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
//本题需要多次匹配，所以把next数组的m位置也加上了
//这里的next定义是不包括当前元素的最大相同前后缀长度
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
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size(),m=s2.size();
	int x=0,y=0;
	auto next=Next(s2);
	vector<int> ans;
	while (x < n) {
		if (s1[x] == s2[y]) {
			x++;
			y++;
		}
		else if (y == 0) x++;
		else y=next[y];
		
		if (y == m) {
			ans.push_back(x-m+1);
			y=next[y];
		}
	}
	
	for(auto e1 : ans) cout<<e1<<endl;
	for(int i=1;i<=m;i++) cout<<next[i]<<" ";
	
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









