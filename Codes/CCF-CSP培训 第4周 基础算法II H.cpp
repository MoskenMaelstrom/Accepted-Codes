// Problem: H - 朋友
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/H
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

struct DSU {
	vector<int> f,siz;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(),f.end(),0);
		siz.assign(n,1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool same(int x,int y) {
		return find(x) == find(y);
	}
	
	bool merge(int x,int y) {
		x=find(x);
		y=find(y);
		if (x == y) return 0;
		siz[x] += siz[y];
		f[y]=x;
		return 1;
	}
	
	int elesize(int x) {
		return siz[find(x)];
	}
	
	//返回根的数量
	int count() {
		unordered_set<int> roots;
		for(int i=0;i<f.size();i++) roots.insert(find(i));
		return roots.size();
	}
};

void solve()
{
    int N,M,P,Q;
    cin>>N>>M>>P>>Q;

    DSU A(N+1), B(M+1);

    for(int i=0;i<P;i++){
        int x,y; cin>>x>>y;
        if(x>=1 && x<=N && y>=1 && y<=N) A.merge(x,y);
    }

    for(int i=0;i<Q;i++){
        int x,y; cin>>x>>y;
        int xx = -x;
        int yy = -y;
        if(xx>=1 && xx<=M && yy>=1 && yy<=M) B.merge(xx,yy);
    }

    int sizeA = A.elesize(1);
    int sizeB = B.elesize(1);

    int ans = min(sizeA, sizeB);
    cout<<ans<<"\n";

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









