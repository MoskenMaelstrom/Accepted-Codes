// Problem: A. AUS
// Contest: Codeforces - The 2024 ICPC Asia Hangzhou Regional Contest (The 3rd Universal Cup. Stage 25: Hangzhou)
// URL: https://codeforces.com/gym/105657/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
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
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	if (s1.size() != s2.size()) {cout<<"NO\n";return;}
	if (s1.size() == s2.size() and s1.size() != s3.size()) {cout<<"YES\n";return;}
	
	DSU dsu(26);
	for(int i=0;i<s1.size();i++) {
		dsu.merge(s1[i]-'a',s2[i]-'a');
	}
	for(int i=0;i<s1.size();i++) {
		if (dsu.find(s1[i]-'a') != dsu.find(s3[i]-'a')) {cout<<"YES\n";return;}
	}
	cout<<"NO\n";
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







