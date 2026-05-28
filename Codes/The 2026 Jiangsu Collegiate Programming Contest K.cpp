// Problem: K. Stock Trading
// Contest: Codeforces - The 2026 Jiangsu Collegiate Programming Contest, The 2026 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106550/problem/K
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct Info {
	int buy=0;
	int sell=0;
	int sum=0;
};

struct SegTree {
    int n;
    vector<Info> tree;
	
    SegTree(int _) {
        n=_;
        tree.resize(n*4);
    }
	
	int getsum(int p,int k) {
		if (k <= 0) return 0;
		if (k == tree[p].sell) return tree[p].sum;
		int cnt=min(tree[p*2].buy,tree[p*2+1].sell);
		int rest=tree[p*2+1].sell-cnt;
		if (k <= rest) return getsum(2*p+1,k);
		else return getsum(2*p,k-rest)+tree[p].sum-tree[p*2].sum;
	}
	
    void push_up(int p) {
		int cnt=min(tree[p*2].buy,tree[p*2+1].sell);
		tree[p].buy=tree[p*2].buy+tree[p*2+1].buy-cnt;
		tree[p].sell=tree[p*2].sell+tree[p*2+1].sell-cnt;
		tree[p].sum=tree[p*2].sum+getsum(p*2+1,tree[p*2+1].sell-cnt);
    }
	
    void build(int p,int l,int r,vector<int>& v,int a) {
        if (l == r) {
        	if (v[l] <= a) tree[p].buy=1;
            return;
        }
        int m=l+r>>1;
        build(p*2,l,m,v,a);
        build(p*2+1,m+1,r,v,a);
    	push_up(p);
    }

    void update(int p,int l,int r,int id,int val) {
        if (l == r) {
        	tree[p].buy=0;
        	tree[p].sell=1;
        	tree[p].sum=val;
            return;
        }
        int m=l+r>>1;
        if (id <= m) update(p*2,l,m,id,val);
        else update(p*2+1,m+1,r,id,val);
        push_up(p);
    }
};

void solve()
{
	int n,a;
	cin>>n>>a;
	int sum0=0;
	vector<int> v(n);
	vector<array<int,2>> sells;
	for(int i=0;i<n;i++) {
		cin>>v[i];
		if (v[i] <= a) sum0+=v[i];
		else sells.push_back({v[i],i});
	}
	SegTree st(n);
	st.build(1,0,n-1,v,a);
	int m;
	cin>>m;
	vector<array<int,2>> q(m);
	for(int i=0;i<m;i++) cin>>q[i][0],q[i][1]=i;
	ranges::sort(sells,greater<array<int,2>>());
	ranges::sort(q,greater<array<int,2>>());
	
	int cur=0;
	int sum1=0;
	vector<int> ans(m);
	for(auto [b,id] : q) {
		while (cur < sells.size() and sells[cur][0] >= b) {
			st.update(1,0,n-1,sells[cur][1],sells[cur][0]);
			sum1+=sells[cur][0];
			cur++;
		}
		ans[id]=sum1-st.tree[1].sum+st.tree[1].buy*v[n-1];
	}
	
	for(auto e1 : ans) cout<<e1-sum0<<" ";
	cout<<"\n";
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







