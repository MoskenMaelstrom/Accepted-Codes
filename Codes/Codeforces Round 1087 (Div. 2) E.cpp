// Problem: E. A Trivial String Problem
// Contest: Codeforces - Codeforces Round 1087 (Div. 2)
// URL: https://codeforces.com/contest/2209/problem/E
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
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
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	auto dfs=[&](string s1) -> int {
		auto next=Next(s1);
		vector<int> dp(s1.size()+1);
		vector<int> f(s1.size()+1);
		int sum=0;
		for(int i=1;i<=s1.size();i++) {
			if (next[i] == 0) dp[i]=i;
			else dp[i]=dp[next[i]];
			f[i]=f[i-dp[i]]+1;
			sum+=f[i];
		}
		return sum;
	};
	
	while (q--) {
		int l,r;
		cin>>l>>r;
		l--,r--;
		cout<<dfs(s.substr(l,r-l+1))<<"\n";
	}
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







