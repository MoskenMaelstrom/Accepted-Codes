// Problem: C. Stepan and Permutation
// Contest: Codeforces - Codeforces Round 1109 (Div. 3)
// URL: https://codeforces.com/contest/2244/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct DSU {
    vector<int> f,siz;
    int cnt;

    DSU(int n) {init(n);}

    void init(int n) {
        f.resize(n);
        iota(f.begin(),f.end(),0);
        siz.assign(n,1);
        cnt=n;
    }

    int find(int x) {
    	if (x == f[x]) return x;
    	int r=find(f[x]);
        return f[x]=r;
    }

    bool merge(int x,int y) {
        int fx=find(x);
        int fy=find(y);
        if (fx == fy) return 0;
        siz[fx]+=siz[fy];
        f[fy]=fx;
        cnt--;
        return 1;
    }

    int esize(int x) {
        return siz[find(x)];
    }
};

void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	DSU dsu(n+1);
	for(int i=1;i<=n;i++) {
		if (i+x <= n) dsu.merge(a[i],a[i+x]);
		if (i+y <= n) dsu.merge(a[i],a[i+y]);
	}
	
	for(int i=1;i<=n;i++) {
		if (dsu.find(a[i]) != dsu.find(i)) {cout<<"NO\n";return;}
	}
	cout<<"YES\n";
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







