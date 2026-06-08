// Problem: P2292 [HNOI2004] L 语言
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2292
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=1e5;
int tree[N][26];
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

int query(const string& s) {
	int cur=0;
	for(char c : s) {
		if (tree[cur][c-'a'] == 0) return 0;
		cur=tree[cur][c-'a'];
	}
	return ed[cur];
}

int querypre(const string& s) {
	int cur=0;
	for(char c : s) {
		if (tree[cur][c-'a'] == 0) return 0;
		cur=tree[cur][c-'a'];
	}
	return pass[cur];
}

void erase(const string& s) {
	if (query(s) == 0) return;
	int cur=0;
	pass[cur]--;
	for(char c : s) {
		if (--pass[tree[cur][c-'a']] == 0) {
			tree[cur][c-'a']=0;
			return;
		}
		cur=tree[cur][c-'a'];
	}
	ed[cur]--;
}

bool dp[2000005];
void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		insert(s);
	}
	while (q--) {
		string s;
		cin>>s;
		int m=s.size();
		memset(dp,0,(m+5)*sizeof(bool));
		dp[0]=1;
		int ans=0;
		for(int i=0;i<m;i++) {
			if (i > ans) break;
			if (!dp[i]) continue;
			int cur=0;
			for(int j=i;j<m;j++) {
				if (tree[cur][s[j]-'a'] == 0) break;
				cur=tree[cur][s[j]-'a'];
				if (ed[cur]) {
					dp[j+1]=1;
					ans=max(ans,j+1);
				}
			}
		}
		cout<<ans<<"\n";
	}
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







