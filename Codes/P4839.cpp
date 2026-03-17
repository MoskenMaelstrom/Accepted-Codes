// Problem: P4839 P 哥的桶
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4839
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
// #define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct B {
	vector<int> b1;
    bool zero;
    B() : b1(31,0),zero(0) {}

    void insert(int x) {
        for (int i=30;i>=0;i--) {
            if (x>>i&1) {
                if (!b1[i]) {b1[i]=x;return;}
                x^=b1[i];
            }
        }
        zero=1;
    }
};

struct SegTree {
	int n;
	vector<B> b;
	SegTree(int n_) {
		n=n_;
		b.resize(n*4);
	}
	
	void Add(int v,int l,int r,int p,int val) {
		if (l == r) {b[v].insert(val);return;}
		int m=l+r>>1;
		if (p <= m) Add(2*v,l,m,p,val);
		else Add(2*v+1,m+1,r,p,val);
		b[v]=b[v*2];
		for(int i=30;i>=0;i--) {
			b[v].insert(b[v*2+1].b1[i]);
		}
	}
	
	B query(int v,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return B();
		if (ql <= l and r <= qr) return b[v];
		int m=l+r>>1;
		auto res1=query(2*v,l,m,ql,qr);
		auto res2=query(2*v+1,m+1,r,ql,qr);
		for(int i=30;i>=0;i--) {
			res1.insert(res2.b1[i]);
		}
		return res1;
	}
};

void solve()
{
	int n,m;
	cin>>n>>m;
	SegTree st(m+1);
	for(int i=0;i<n;i++) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int k,x;
			cin>>k>>x;
			st.Add(1,0,m,k,x);
		}
		else {
			int l,r;
			cin>>l>>r;
			auto b=st.query(1,0,m,l,r).b1;
			int ans=0;
			for(int i=30;i>=0;i--) {
				if ((ans^b[i]) > ans) ans^=b[i];
			}
			cout<<ans<<"\n";
		}
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







