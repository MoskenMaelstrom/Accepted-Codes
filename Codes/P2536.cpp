// Problem: P2536 [AHOI2005] 病毒检测
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2536
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
// #define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=3e5;
bitset<1001> vis[N];
int tree[N][4];
int pass[N];
int ed[N];
int len=1;

void insert(const string& s) {
	int cur=0;
	pass[cur]++;
	for(char c : s) {
		if (tree[cur][c-'a'] == 0) tree[cur][c-'a']=len++;
		cur=tree[cur][c-'a'];
		pass[cur]++;
	}
	ed[cur]++;
}

void solve()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if (s[i] == 'A') s[i]='a';
		else if (s[i] == 'C') s[i]='b';
		else if (s[i] == 'T') s[i]='c';
		else if (s[i] == 'G') s[i]='d';
	}
	int len=s.size();
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string ss;
		cin>>ss;
		for(int i=0;i<ss.size();i++) {
			if (ss[i] == 'A') ss[i]='a';
			else if (ss[i] == 'C') ss[i]='b';
			else if (ss[i] == 'T') ss[i]='c';
			else if (ss[i] == 'G') ss[i]='d';
		}
		insert(ss);
	}
	
	int ans=0;
	auto dfs=[&](auto&& self,int u,int p) -> void {
		if (vis[u][p]) return;
		vis[u][p]=1;
		if (p == len) {ans+=ed[u];return;}
		
		if (s[p] == '*') {
			self(self,u,p+1);
			for(int i=0;i<4;i++) {
				int v=tree[u][i];
				if (v) self(self,v,p+1);
			}
			for(int i=0;i<4;i++) {
				int v=tree[u][i];
				if (v) self(self,v,p);
			}
		}
		else if (s[p] == '?') {
			for(int i=0;i<4;i++) {
				int v=tree[u][i];
				if (v) self(self,v,p+1);
			}
		}
		else {
			int v=tree[u][s[p]-'a'];
			if (v) self(self,v,p+1);
		}
	};
	
	dfs(dfs,0,0);
	cout<<n-ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







