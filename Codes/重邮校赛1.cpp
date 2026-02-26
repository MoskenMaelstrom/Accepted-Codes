#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
// #define int long long
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

const int N=1e6;
void solve()
{
	int n,m;
	cin>>n>>m;
	DSU dsu(N);
	
	int len=0;
	unordered_map<int,int> mp;
	while (m--) {
		int n1,n2;
		cin>>n1>>n2;
		vector<int> a(n1),b(n2);
		for(int i=0;i<n1;i++) cin>>a[i];
		for(int i=0;i<n2;i++) cin>>b[i];
		
		if (n1 != 0 and n2 != 0) {
			len++;
			for(int i=0;i<n1;i++) {
				if (mp.count(a[i]) == 0) mp[a[i]]=len;
				else dsu.merge(mp[a[i]],len);
			}
			
			len++;
			for(int i=0;i<n2;i++) {
				if (mp.count(b[i]) == 0) mp[b[i]]=len;
				else dsu.merge(mp[b[i]],len);
			}
			
			dsu.merge(mp[a[0]],mp[b[0]]);
		}
	}
	
	int q;
	cin>>q;
	while (q--) {
		int n1,n2;
		cin>>n1>>n2;
		if (mp.count(n1) and mp.count(n2) and dsu.same(mp[n1],mp[n2])) cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	
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









