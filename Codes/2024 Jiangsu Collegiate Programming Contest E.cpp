// Problem: E. Divide
// Contest: Codeforces - 2024 Jiangsu Collegiate Programming Contest
// URL: https://codeforces.com/gym/105161/problem/E
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

struct PSegTree {
    struct Node {
        int ls,rs,cnt;
    };
    int maxn;
    vector<Node> tr;
    vector<int> root;
    
    PSegTree(int _,int ops) {
        maxn=_;
        tr.reserve(1+ops*(__lg(maxn)+2)); 
        tr.push_back({0,0,0});
        root.push_back(0);
    }
    
    int insert(int prev,int l,int r,int val) {
        int p=tr.size();
        tr.push_back(tr[prev]);
        tr[p].cnt++;
        
        if (l == r) return p;
        int m=l+(r-l)/2;
        if (val <= m) tr[p].ls=insert(tr[prev].ls,l,m,val);
        else tr[p].rs=insert(tr[prev].rs,m+1,r,val);
        return p;
    }
    
    void add(int val) {
        int cur=insert(root.back(),1,maxn,val);
        root.push_back(cur);
    }
    
    int query(int u,int v,int l,int r,int k) {
        if (l == r) return l;
        int m=l+(r-l)/2;
        int c=tr[tr[v].ls].cnt-tr[tr[u].ls].cnt;
        if (k <= c) return query(tr[u].ls,tr[v].ls,l,m,k);
        else return query(tr[u].rs,tr[v].rs,m+1,r,k-c);
    }
};

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> b(20*n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<20;j++) {
			b[i*20+j]=a[i]>>j;
		}
	}
	
	auto c=b;
	n=b.size();
	ranges::sort(c);
	c.erase(unique(c.begin(),c.end()),c.end());
	PSegTree st(c.size(),n);
	for(int i=0;i<n;i++) st.add(ranges::lower_bound(c,b[i])-c.begin()+1);
	
	while (q--) {
		int l,r,k;
		cin>>l>>r>>k;
		l=(l-1)*20+1;
		r=r*20;
		int rk=r-l+1-k;
		if (rk <= 0) cout<<0<<"\n";
		else cout<<c[st.query(st.root[l-1],st.root[r],1,c.size(),rk)-1]<<"\n";
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







