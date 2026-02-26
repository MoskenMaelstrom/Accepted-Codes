// Problem: G. Shorten the Array
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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


constexpr int N=1e5*31;
int tot;
int trie[N][2];
int cnt[N];

int newNode() {
	int x=++tot;
	trie[x][0]=trie[x][1]=0;
	cnt[x]=0;
	return x;
}

void init() {
	tot=0;
	newNode();
}

void add(int x,int t) {
	int o=1;
	for(int i=30;i>=0;i--) {
		int &p=trie[o][x>>i&1];
		if (p == 0) p=newNode();
		o=p;
		cnt[o]+=t;
	}
}

int query(int x) {
	int o=1;
	int ans=0;
	for(int i=30;i>=0;i--) {
		int d=x>>i&1;
		if (cnt[trie[o][d^1]]) {
			ans|=1<<i;
			d^=1;
		}
		o=trie[o][d];
	}
	return ans;
}


void solve()
{
	init();
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	int ans=n+1;
	for(int i=0,j=0;i<n;i++) {
		add(a[i],1);
		while (j <= i and query(a[i]) >= k) {
			ans=min(ans,i-j+1);
			add(a[j],-1);
			j++;
		}
	}
	
	if (ans == n+1) cout << -1 << endl;
	else {
		cout<<ans<<endl;
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









