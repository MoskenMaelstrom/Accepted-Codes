// Problem: A. Needle in a Haystack
// Contest: Codeforces - Codeforces Round 1069 (Div. 1)
// URL: https://codeforces.com/contest/2174/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

void solve()
{
	string s1,s2;
	cin>>s1>>s2;
	vector<int> c1(26),c2(26);
	for(int i=0;i<s1.size();i++) {
		c1[s1[i]-'a']++;
	}
	for(int i=0;i<s2.size();i++) {
		c2[s2[i]-'a']++;
	}
	
	for(int i=0;i<26;i++) {
		if (c1[i] > c2[i]) {
			cout<<"Impossible\n";
			return;
		}
		c2[i]-=c1[i];
	}
	int p=0;
	string ans="";
	for(int i=0;i<26;i++) {
		while (c2[i] != 0) {
			if (p == s1.size()) ans+=i+'a',c2[i]--;
			else if (p != s1.size() and i+'a' < s1[p]) ans+=i+'a',c2[i]--;
			else ans+=s1[p++];
		}
	}
	while (p != s1.size()) ans+=s1[p++];
	cout<<ans<<"\n";
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







