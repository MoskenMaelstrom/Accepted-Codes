// Problem: SP4033 PHONELST - Phone List
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/SP4033
// Memory Limit: 1495 MB
// Time Limit: 532 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=1e5;
int tree[N][10];
int pass[N];
int ed[N];
int len=1;

void insert(const string& s) {
	int cur=0;
	pass[cur]++;
	for(char c : s) {
		if (tree[cur][c-'0'] == 0) tree[cur][c-'0']=len++;
		cur=tree[cur][c-'0'];
		pass[cur]++;
	}
	ed[cur]++;
}

int query(const string& s) {
	int cur=0;
	for(char c : s) {
		if (tree[cur][c-'0'] == 0) return 0;
		cur=tree[cur][c-'0'];
	}
	return ed[cur];
}

int querypre(const string& s) {
	int cur=0;
	for(char c : s) {
		if (tree[cur][c-'0'] == 0) return 0;
		cur=tree[cur][c-'0'];
	}
	return pass[cur];
}

void erase(const string& s) {
	if (query(s) == 0) return;
	int cur=0;
	pass[cur]--;
	for(char c : s) {
		if (--pass[tree[cur][c-'0']] == 0) {
			tree[cur][c-'0']=0;
			return;
		}
		cur=tree[cur][c-'0'];
	}
	ed[cur]--;
}

void solve()
{
	for(int i=0;i<len;i++) {
		pass[i]=0;
		ed[i]=0;
		for(int j=0;j<10;j++) tree[i][j]=0;
	}
	len=1;
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		insert(s);
	}
	bool ok=0;
	for(int i=0;i<len;i++) {
		if (ed[i] and pass[i] > 1) ok=1;
	}
	if (ok) cout<<"NO\n";
	else cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







