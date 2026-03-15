// Problem: I. Essentially Different Suffixes
// Contest: Codeforces - The 2025 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105949/problem/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=4e5;
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

void solve()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		ranges::reverse(s);
		insert(s);
	}
	cout<<len-1;
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







