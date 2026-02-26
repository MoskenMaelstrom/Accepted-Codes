// Problem: Sensei and Yuuka Going Shopping (yuuka)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108307/F
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
// #define int long long
using namespace std;

struct SegTree {
private:
    vector<int> maxn, add, change, mark, arr;
    vector<int> max_idx;
    
    void up(int i) {
        if (maxn[i << 1] >= maxn[i << 1 | 1]) {
            maxn[i] = maxn[i << 1];
            max_idx[i] = max_idx[i << 1];
        } else {
            maxn[i] = maxn[i << 1 | 1];
            max_idx[i] = max_idx[i << 1 | 1];
        }
    }
    
    void down(int i) {
        if (mark[i]) {
            Changelazy(i << 1, change[i]);
            Changelazy(i << 1 | 1, change[i]);
            mark[i] = 0;
        }
        if (add[i] != 0) {
            Addlazy(i << 1, add[i]);
            Addlazy(i << 1 | 1, add[i]);
            add[i] = 0;
        }
    }
    
    void Changelazy(int i, int v) {
        maxn[i] = v;
        add[i] = 0;
        change[i] = v;
        mark[i] = 1;
    }
    
    void Addlazy(int i, int v) {
        maxn[i] += v;
        add[i] += v;
    }
    
    void build(int l, int r, int i) {
        if (l == r) {
            maxn[i] = arr[l];
            max_idx[i] = l;
        } else {
            int mid = l + r >> 1;
            build(l, mid, i << 1);
            build(mid + 1, r, i << 1 | 1);
            up(i);
        }
    }
    
    void Change(int jl, int jr, int v, int l, int r, int i) {
        if (jl <= l && r <= jr) Changelazy(i, v);
        else {
            int mid = l + r >> 1;
            down(i);
            if (jl <= mid) Change(jl, jr, v, l, mid, i << 1);
            if (mid + 1 <= jr) Change(jl, jr, v, mid + 1, r, i << 1 | 1);
            up(i);
        }
    }
    
    void Add(int jl, int jr, int v, int l, int r, int i) {
        if (jl <= l && r <= jr) Addlazy(i, v);
        else {
            int mid = l + r >> 1;
            down(i);
            if (jl <= mid) Add(jl, jr, v, l, mid, i << 1);
            if (mid + 1 <= jr) Add(jl, jr, v, mid + 1, r, i << 1 | 1);
            up(i);
        }
    }
    
    int query(int jl, int jr, int l, int r, int i) {
        if (jl <= l && r <= jr) return maxn[i];
        int mid = l + r >> 1;
        down(i);
        int ans = INT_MIN;
        if (jl <= mid) ans = max(ans, query(jl, jr, l, mid, i << 1));
        if (mid + 1 <= jr) ans = max(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
        return ans;
    }
    
    pair<int, int> query_max_with_index(int jl, int jr, int l, int r, int i) {
        if (jl <= l && r <= jr) return {maxn[i], max_idx[i]};
        int mid = l + r >> 1;
        down(i);
        pair<int, int> left = {INT_MIN, -1}, right = {INT_MIN, -1};
        if (jl <= mid) left = query_max_with_index(jl, jr, l, mid, i << 1);
        if (mid + 1 <= jr) right = query_max_with_index(jl, jr, mid + 1, r, i << 1 | 1);
        return left.first >= right.first ? left : right;
    }

public:
    SegTree() {}
    SegTree(const vector<int>& input_arr) : arr(input_arr) {
        int n = arr.size();
        maxn.assign(4 * n, 0);
        add.assign(4 * n, 0);
        change.assign(4 * n, 0);
        mark.assign(4 * n, 0);
        max_idx.assign(4 * n, 0);
        build(0, n - 1, 1); 
    }
    
    void rChange(int l, int r, int v) {
        Change(l, r, v, 0, arr.size() - 1, 1);
    }
    
    void rAdd(int l, int r, int v) {
        Add(l, r, v, 0, arr.size() - 1, 1);
    }
    
    int Max(int l, int r) {
        return query(l, r, 0, arr.size() - 1, 1);
    }
    
    // left
    pair<int, int> MaxWithIndex(int l, int r) {
        return query_max_with_index(l, r, 0, arr.size() - 1, 1);
    }
    
    int MaxIndex(int l, int r) {
        return MaxWithIndex(l, r).second;
    }
};

const int N=1e6+1;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector val(N,vector<int>(0));
	unordered_set<int> used;
	for(int i=0;i<n;i++) {
		val[a[i]].push_back(i);
		used.insert(a[i]);
	}
	
	vector up(n+1,vector<array<int,3>>(0));//{L,R,+1/-1} 
	for(auto num : used) {
		int len=val[num].size();
		auto p=val[num];
		if (len < 3) continue;
		for(int i=1;i<len-1;i++) {
			// if (p[len-1] < p[i]+1) continue;
			up[p[i-1]+1].push_back({p[i]+1,p[len-1],1});
			up[p[i]+1].push_back({p[i]+1,p[len-1],-1});
		}
	}
	
	vector<int> b(n);
	SegTree st(b);
	int cnt=0;
	array<int,2> ans={1,2};
	for(int l=1;l<n-1;l++) {
		for(auto [L,R,d] : up[l]) {
			st.rAdd(L,R,d);
		}
		if (st.Max(0,n-1) > cnt) {
			cnt=st.Max(0,n-1);
			ans={l,st.MaxIndex(0,n-1)};
		}
	}
	
	cout<<cnt<<'\n';
	cout<<ans[0]+1<<' '<<ans[1]+1<<'\n';
	
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









