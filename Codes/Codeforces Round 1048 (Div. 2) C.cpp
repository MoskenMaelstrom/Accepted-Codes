// Problem: C. Cake Assignment
// Contest: Codeforces - Codeforces Round 1048 (Div. 2)
// URL: https://codeforces.com/contest/2139/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
private:
    struct Node {
        int max_val;
        int min_val;
        bool is_inc;
        bool is_dec;
        int left_val;
        int right_val;
    };
    
    vector<Node> tree;
    vector<int> arr;
    vector<int> add;
    vector<int> change;
    vector<bool> mark;
    
    void merge(Node &parent, const Node &left, const Node &right) {
        parent.max_val = max(left.max_val, right.max_val);
        parent.min_val = min(left.min_val, right.min_val);
        parent.left_val = left.left_val;
        parent.right_val = right.right_val;
        
        parent.is_inc = left.is_inc && right.is_inc && (left.right_val <= right.left_val);
        parent.is_dec = left.is_dec && right.is_dec && (left.right_val >= right.left_val);
    }
    
    void build(int l, int r, int i) {
        if (l == r) {
            tree[i].max_val = arr[l];
            tree[i].min_val = arr[l];
            tree[i].is_inc = true;
            tree[i].is_dec = true;
            tree[i].left_val = arr[l];
            tree[i].right_val = arr[l];
        } else {
            int mid = l + r >> 1;
            build(l, mid, i << 1);
            build(mid + 1, r, i << 1 | 1);
            merge(tree[i], tree[i << 1], tree[i << 1 | 1]);
        }
    }
    
    void apply_change(int i, int v) {
        tree[i].max_val = v;
        tree[i].min_val = v;
        tree[i].left_val = v;
        tree[i].right_val = v;
        tree[i].is_inc = true;
        tree[i].is_dec = true;
        change[i] = v;
        add[i] = 0;
        mark[i] = true;
    }
    
    void apply_add(int i, int v) {
        tree[i].max_val += v;
        tree[i].min_val += v;
        tree[i].left_val += v;
        tree[i].right_val += v;
        add[i] += v;
    }
    
    void push_down(int i, int l, int r) {
        if (mark[i]) {
            apply_change(i << 1, change[i]);
            apply_change(i << 1 | 1, change[i]);
            mark[i] = false;
        }
        if (add[i] != 0) {
            apply_add(i << 1, add[i]);
            apply_add(i << 1 | 1, add[i]);
            add[i] = 0;
        }
    }
    
    void update_change(int jl, int jr, int v, int l, int r, int i) {
        if (jl <= l && r <= jr) {
            apply_change(i, v);
            return;
        }
        int mid = l + r >> 1;
        push_down(i, l, r);
        if (jl <= mid) update_change(jl, jr, v, l, mid, i << 1);
        if (mid < jr) update_change(jl, jr, v, mid + 1, r, i << 1 | 1);
        merge(tree[i], tree[i << 1], tree[i << 1 | 1]);
    }
    
    void update_add(int jl, int jr, int v, int l, int r, int i) {
        if (jl <= l && r <= jr) {
            apply_add(i, v);
            return;
        }
        int mid = l + r >> 1;
        push_down(i, l, r);
        if (jl <= mid) update_add(jl, jr, v, l, mid, i << 1);
        if (mid < jr) update_add(jl, jr, v, mid + 1, r, i << 1 | 1);
        merge(tree[i], tree[i << 1], tree[i << 1 | 1]);
    }
    
    Node query_range(int jl, int jr, int l, int r, int i) {
        if (jl <= l && r <= jr) {
            return tree[i];
        }
        int mid = l + r >> 1;
        push_down(i, l, r);
        if (jr <= mid) {
            return query_range(jl, jr, l, mid, i << 1);
        } else if (jl > mid) {
            return query_range(jl, jr, mid + 1, r, i << 1 | 1);
        } else {
            Node left_node = query_range(jl, jr, l, mid, i << 1);
            Node right_node = query_range(jl, jr, mid + 1, r, i << 1 | 1);
            Node res;
            merge(res, left_node, right_node);
            return res;
        }
    }

public:
    SegTree() {}
    SegTree(const vector<int>& input_arr) : arr(input_arr) {
        int n = arr.size();
        tree.resize(4 * n);
        add.assign(4 * n, 0);
        change.assign(4 * n, 0);
        mark.assign(4 * n, false);
        build(0, n - 1, 1);
    }
    
    void rangeChange(int l, int r, int v) {
        update_change(l, r, v, 0, arr.size() - 1, 1);
    }
    
    void rangeAdd(int l, int r, int v) {
        update_add(l, r, v, 0, arr.size() - 1, 1);
    }
    
    // 查询区间是否单调递增
    bool isIncreasing(int l, int r) {
        Node res = query_range(l, r, 0, arr.size() - 1, 1);
        return res.is_inc;
    }
    
    // 查询区间是否单调递减
    bool isDecreasing(int l, int r) {
        Node res = query_range(l, r, 0, arr.size() - 1, 1);
        return res.is_dec;
    }
    
    // 查询区间是否单调（递增或递减）
    bool isMonotonic(int l, int r) {
        Node res = query_range(l, r, 0, arr.size() - 1, 1);
        return res.is_inc || res.is_dec;
    }
    
    // 获取区间最大值
    int getMax(int l, int r) {
        Node res = query_range(l, r, 0, arr.size() - 1, 1);
        return res.max_val;
    }
    
    // 获取区间最小值
    int getMin(int l, int r) {
        Node res = query_range(l, r, 0, arr.size() - 1, 1);
        return res.min_val;
    }
};

void solve()
{
	int k,x;
	cin>>k>>x;
	vector<int> a(k+1),b(k+1);
	vector<int> c(k+1),d(k+1);
	a[k]=1;
	b[k]=1;
	
	for(int i=0;((x>>i) != 0);i++) {
		c[i]=((x>>i)&1);
	}
	for(int i=0;i<=k;i++) {
		d[i]=c[k-i];
	}
	
	vector<int> ans;
	int cnt=0;
	int k1=0;
	for(int i=k;i>=0;i--) {
		if (d[i] == 1) {k1=i;break;}
	}
	for(int i=k1-1;i>=0;i--) {
		if (d[i] == 0) ans.push_back(1);
		else ans.push_back(2);
	}
	
	cout<<ans.size()<<"\n";
	for(auto e1 : ans) cout<<e1<<" ";
	cout<<"\n";
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









