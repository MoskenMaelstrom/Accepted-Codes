// Problem: P3372 【模板】线段树 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3372
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: P3372 【模板】线段树 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3372
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

const int inf=1e18;
struct Info {
	int sum,Max,Min;
	Info() : sum(0),Max(-inf),Min(inf) {};
    Info(int val) : sum(val),Max(val),Min(val) {};
    Info operator+(const Info &other) const {
    	Info res;
    	res.sum=sum+other.sum;
    	res.Min=min(Min,other.Min);
    	res.Max=max(Max,other.Max);
    	return res;
    }
};

struct SegTree {
	int n;
	vector<Info> info;
    vector<int> lazy_add,lazy_set;
    const int no_set = 1e18 + 7; 

	SegTree(int n_) {
		n=n_;
		info.resize(n*4);
        lazy_add.resize(n*4, 0);
        lazy_set.resize(n*4, no_set);
	}
	
    void apply_set(int v, int l, int r, int val) {
        info[v].sum = (r - l + 1) * val;
        info[v].Min = val;
        info[v].Max = val;
        lazy_set[v] = val;
        lazy_add[v] = 0;
    }

    void apply_add(int v, int l, int r, int val) {
        info[v].sum += (r - l + 1) * val;
        info[v].Min += val;
        info[v].Max += val;
        if (lazy_set[v] != no_set) {
            lazy_set[v] += val;
        } else {
            lazy_add[v] += val;
        }
    }

    void pushdown(int v, int l, int r) {
        int m = l + r >> 1;
        if (lazy_set[v] != no_set) {
            apply_set(v * 2, l, m, lazy_set[v]);
            apply_set(v * 2 + 1, m + 1, r, lazy_set[v]);
            lazy_set[v] = no_set;
        }
        if (lazy_add[v] != 0) {
            apply_add(v * 2, l, m, lazy_add[v]);
            apply_add(v * 2 + 1, m + 1, r, lazy_add[v]);
            lazy_add[v] = 0;
        }
    }
	
    void Set(int v, int l, int r, int ql, int qr, int val) {
        if (ql > r or qr < l) return;
        if (ql <= l and r <= qr) {
            apply_set(v, l, r, val);
            return;
        }
        pushdown(v, l, r);
        int m = l + r >> 1;
        Set(v * 2, l, m, ql, qr, val);
        Set(v * 2 + 1, m + 1, r, ql, qr, val);
        info[v] = info[v * 2] + info[v * 2 + 1];
    }

    void Add(int v, int l, int r, int ql, int qr, int val) {
        if (ql > r or qr < l) return;
        if (ql <= l and r <= qr) {
            apply_add(v, l, r, val);
            return;
        }
        pushdown(v, l, r);
        int m = l + r >> 1;
        Add(v * 2, l, m, ql, qr, val);
        Add(v * 2 + 1, m + 1, r, ql, qr, val);
        info[v] = info[v * 2] + info[v * 2 + 1];
    }

	Info query(int v,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return Info();
		if (ql <= l and r <= qr) return info[v];
        pushdown(v, l, r);
		int m=l+r>>1;
		return query(2*v,l,m,ql,qr)+query(2*v+1,m+1,r,ql,qr);
	}
};

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	SegTree st(n+1);
	for(int i=1;i<=n;i++) {
		st.Set(1,0,n,i,i,a[i]);
	}
	while (q--) {
		int o,x,y,k;
		cin>>o>>x>>y;
		if (o == 1) {
			cin>>k;
			st.Add(1,0,n,x,y,k);
		}
		else cout<<st.query(1,0,n,x,y).sum<<endl;
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







