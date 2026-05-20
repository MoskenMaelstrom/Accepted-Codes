// Problem: G. Gifts from Knowledge
// Contest: Codeforces - The 2023 ICPC Asia Jinan Regional Contest (The 2nd Universal Cup. Stage 17: Jinan)
// URL: https://codeforces.com/gym/104901/problem/G
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=1e9+7;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

struct DSU {
    vector<int> f,siz;
    vector<int> d;
    bool ok=1;
    int cnt;

    DSU(int n) {init(n);}

    void init(int n) {
        f.resize(n);
        iota(f.begin(),f.end(),0);
        siz.assign(n,1);
        d.assign(n,0);
        cnt=n;
    }

    int find(int x) {
    	if (x == f[x]) return x;
    	int r=find(f[x]);
    	d[x]^=d[f[x]];
        return f[x]=r;
    }

    bool merge(int x,int y,int w) {
        int fx=find(x);
        int fy=find(y);
        if (fx == fy) {
        	if (d[x]^d[y] != w) ok=0;
        	return 0;
        }
        siz[fx]+=siz[fy];
        f[fy]=fx;
        d[fy]=d[x]^d[y]^w;
        cnt--;
        return 1;
    }

    int esize(int x) {
        return siz[find(x)];
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		for(int j=0;j<m;j++) a[i][j]=s[j]-'0';
	}
	
	for(int j=0;j<m/2;j++) {
		int cnt=0;
		for(int i=0;i<n;i++) {
			cnt+=a[i][j]+a[i][m-j-1];
		}
		if (cnt >= 3) {cout<<0<<"\n";return;}
	}
	if (m&1) {
		int cnt=0;
		for(int i=0;i<n;i++) {
			cnt+=a[i][m/2];
		}
		if (cnt >= 2) {cout<<0<<"\n";return;}
	}
	
	
	DSU dsu(n);
	for(int j=0;j<m/2;j++) {
		vector<int> vec;
		for(int i=0;i<n;i++) {
			if (a[i][j] or a[i][m-j-1]) vec.push_back(i);
		}
		if (vec.size() == 2) {
			int u=vec[0];
			int v=vec[1];
			int w=a[u][j] == a[v][j];
			dsu.merge(u,v,w);
		}
	}
	
	if (dsu.ok == 0) cout<<"0\n";
	else cout<<Pow(2,dsu.cnt)<<"\n";
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







