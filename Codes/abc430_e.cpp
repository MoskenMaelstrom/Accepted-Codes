// Problem: E - Shift String
// Contest: AtCoder - AtCoder Beginner Contest 430
// URL: https://atcoder.jp/contests/abc430/tasks/abc430_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
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
	s1=s1+s1;
	int n=s1.size();
	int m=s2.size();
	auto next=Next(s2);
	int x=0,y=0;
	while (x < n and y < m) {
		if (s1[x] == s2[y]) x++,y++;
		else if (y == 0) x++;
		else y=next[y];
		if (y == m) {
			cout<<x-m<<"\n";
			return;
		}
	}
	cout<<"-1\n";
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







