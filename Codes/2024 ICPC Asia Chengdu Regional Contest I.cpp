// Problem: I. Good Partitions
// Contest: Codeforces - 2024 ICPC Asia Chengdu Regional Contest (The 3rd Universal Cup. Stage 15: Chengdu)
// URL: https://codeforces.com/gym/105486/problem/I
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

struct SegTree {
    struct Node {
        int l, r;
        int gcd_val;
    };
    
    vector<Node> tree;
    vector<int> arr;
    int n;
    
    SegTree(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    void build(int idx, int l, int r) {
        tree[idx].l = l;
        tree[idx].r = r;
        if (l == r) {
            tree[idx].gcd_val = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        tree[idx].gcd_val = gcd(tree[idx * 2].gcd_val, tree[idx * 2 + 1].gcd_val);
    }
    
    void update(int idx, int pos, int val) {
        if (tree[idx].l == tree[idx].r) {
            tree[idx].gcd_val = val;
            return;
        }
        int mid = (tree[idx].l + tree[idx].r) / 2;
        if (pos <= mid) update(idx * 2, pos, val);
        else update(idx * 2 + 1, pos, val);
        tree[idx].gcd_val = gcd(tree[idx * 2].gcd_val, tree[idx * 2 + 1].gcd_val);
    }
    
    int query(int idx, int l, int r) {
        if (l <= tree[idx].l && tree[idx].r <= r) {
            return tree[idx].gcd_val;
        }
        int mid = (tree[idx].l + tree[idx].r) / 2;
        if (r <= mid) return query(idx * 2, l, r);
        if (l > mid) return query(idx * 2 + 1, l, r);
        return gcd(query(idx * 2, l, r), query(idx * 2 + 1, l, r));
    }
    
    // 对外接口
    void update(int pos, int val) { update(1, pos, val); }
    int query(int l, int r) { return query(1, l, r); }
};

const int N=2e5;
int fac[N+1];
void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector<int> b(n+1);
	for(int i=2;i<=n;i++) {
		if (a[i-1] > a[i]) b[i]=i-1;
	}
	SegTree st(b);
	int res=st.query(1,n);
	cout<<(res ? fac[res] : n)<<"\n";
 	
	while (q--) {
		int idx,v;
		cin>>idx>>v;
		int pre=a[idx];
		
		if (idx != 1) {
			if (a[idx-1] > pre and a[idx-1] <= v) {
				st.update(idx,0);
			}
			else if (a[idx-1] <= pre and a[idx-1] > v) {
				st.update(idx,idx-1);
			}
		}
		
		if (idx != n) {
			if (pre > a[idx+1] and v <= a[idx+1]) {
				st.update(idx+1,0);
			}
			else if (pre <= a[idx+1] and v > a[idx+1]) {
				st.update(idx+1,idx);
			}
		}
		res=st.query(1,n);
		cout<<(res ? fac[res] : n)<<"\n";
		a[idx]=v;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	for(int i=1;i<=N;i++) {
		for(int j=i;j<=N;j+=i) fac[j]++;
	}
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









