// Problem: F. Wildflower
// Contest: Codeforces - Codeforces Round 1029 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2117/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

//带mod
int pow(int base, int exp, int mod) {
    int res = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return res;
}

const int p=1e9+7;
void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<int>(0));
	vector<int> fa(n);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<bool> mark(n);
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		mark[u]=1;
		for(auto v : adj[u]) {
			if (mark[v]) continue;
			fa[v]=u;
			q.push(v);
		}
	}
	
	vector<int> du(n);//出度
	for(int i=1;i<n;i++) {
		du[fa[i]]++;
	}
	
	// for(auto e1 : du) cout<<e1<<" ";
	// cout<<endl;
	
	if (*ranges::max_element(du) == 1) {
		cout<<pow(2,n,p)<<"\n";
	}
	else if (ranges::count(du,2) >= 2 or *ranges::max_element(du) > 2) cout<<"0\n";
	else {
		int P=ranges::find(du,2)-du.begin();
		vector<int> vec;
		for(int i=0;i<n;i++) if (du[i] == 0) vec.push_back(i);
		int u=vec[0],v=vec[1];
		int c1=0,c2=0;
		while (u != P) {u=fa[u];c1++;}
		while (v != P) {v=fa[v];c2++;}
		
		int cha=abs(c1-c2);
		int c=0;
		while (P != 0) {
			P=fa[P];
			c++;
		}
		if (cha != 0) cout<<pow(2,c+cha,p)*3%p<<"\n";
		else cout<<pow(2,c+cha+2,p)%p<<"\n";
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









