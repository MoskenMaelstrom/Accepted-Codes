// Problem: B. Barkley III
// Contest: Codeforces - The 2024 ICPC Asia Hangzhou Regional Contest (The 3rd Universal Cup. Stage 25: Hangzhou)
// URL: https://codeforces.com/gym/105657/problem/B
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

const int inf=1e18;
struct Info {
	ull g,f;
	Info() : g(~0ull),f(0) {};
    Info(ull val) : g(val),f(~val) {};
    Info operator+(const Info &other) const {
    	Info res;
    	res.g=g&other.g;
    	res.f=(f&other.g)|(g&other.f);
    	return res;
    }
};

struct SegTree {
	int n;
	vector<Info> info;
    vector<ull> lazy_and;

	SegTree(int n_) {
		n=n_;
		info.resize(n*4);
        lazy_and.resize(n*4, ~0ull);
	}

    void apply_and(int v, int l, int r, ull val) {
    	info[v].g&=val;
    	lazy_and[v]&=val;
    	if (l == r) info[v].f=~info[v].g;
    	else info[v].f&=val;
    }

    void pushdown(int v, int l, int r) {
        int m = l + r >> 1;
        if (lazy_and[v] != ~0ull) {
            apply_and(v * 2, l, m, lazy_and[v]);
            apply_and(v * 2 + 1, m + 1, r, lazy_and[v]);
            lazy_and[v] = ~0ull;
        }
    }

    void And(int v, int l, int r, int ql, int qr, ull val) {
        if (ql > r or qr < l) return;
        if (ql <= l and r <= qr) {
            apply_and(v, l, r, val);
            return;
        }
        pushdown(v, l, r);
        int m = l + r >> 1;
        And(v * 2, l, m, ql, qr, val);
        And(v * 2 + 1, m + 1, r, ql, qr, val);
        info[v] = info[v * 2] + info[v * 2 + 1];
    }

	void Set(int v,int l,int r,int p,ull val) {
		if (l == r) {
			info[v]=Info(val);
			lazy_and[v]=~0ull;
			return;
		}
        pushdown(v, l, r);
		int m=l+r>>1;
		if (p <= m) Set(2*v,l,m,p,val);
		else Set(2*v+1,m+1,r,p,val);
		info[v]=info[v*2]+info[v*2+1];
	}
	
	Info query(int v,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return Info();
		if (ql <= l and r <= qr) return info[v];
        pushdown(v, l, r);
		int m=l+r>>1;
		return query(2*v,l,m,ql,qr)+query(2*v+1,m+1,r,ql,qr);
	}
	
	int find_id(int v,int l,int r,int ql,int qr,int b) {
		if (l == r) return l;
		pushdown(v,l,r);
		int m=l+r>>1;
		bool left=0;
		if (ql <= l and m <= qr) {
			if (((info[v*2].g>>b)&1) == 0) left=1;
		}
		else if (ql <= m) {
			if (((query(v*2,l,m,ql,qr).g>>b)&1) == 0) left=1;
		}
		if (left) return find_id(v*2,l,m,ql,qr,b);
		else return find_id(v*2+1,m+1,r,ql,qr,b);
	}
};

void solve()
{
	int n,q;
	cin>>n>>q;
	SegTree st(n);
	for(int i=0;i<n;i++) {
		ull val;
		cin>>val;
		st.Set(1,0,n-1,i,val);
	}
	
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int l,r;
			ull x;
			cin>>l>>r>>x;
			l--,r--;
			st.And(1,0,n-1,l,r,x);
		}
		else if (opt == 2) {
			int p;
			ull x;
			cin>>p>>x;
			p--;
			st.Set(1,0,n-1,p,x);
		}
		else {
			int l,r;
			cin>>l>>r;
			l--,r--;
			
			if (st.query(1,0,n-1,l,r).f == 0) cout<<st.query(1,0,n-1,l,r).g<<"\n";
			else {
				int b=64-__builtin_clzll(st.query(1,0,n-1,l,r).f);
				int res=st.find_id(1,0,n-1,l,r,b-1);
				
				ull ans=~0ull;
				if (l < res) ans&=st.query(1,0,n-1,l,res-1).g;
				if (res < r) ans&=st.query(1,0,n-1,res+1,r).g;
				cout<<ans<<"\n";
			}
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







