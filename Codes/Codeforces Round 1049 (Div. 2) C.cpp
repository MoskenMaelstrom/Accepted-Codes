#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int inf = -4e18;

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
            int mid = (l + r) >> 1;
            build(l, mid, i << 1);
            build(mid + 1, r, i << 1 | 1);
            up(i);
        }
    }
    
    void Change(int jl, int jr, int v, int l, int r, int i) {
        if (jl <= l && r <= jr) Changelazy(i, v);
        else {
            int mid = (l + r) >> 1;
            down(i);
            if (jl <= mid) Change(jl, jr, v, l, mid, i << 1);
            if (mid + 1 <= jr) Change(jl, jr, v, mid + 1, r, i << 1 | 1);
            up(i);
        }
    }
    
    void Add(int jl, int jr, int v, int l, int r, int i) {
        if (jl <= l && r <= jr) Addlazy(i, v);
        else {
            int mid = (l + r) >> 1;
            down(i);
            if (jl <= mid) Add(jl, jr, v, l, mid, i << 1);
            if (mid + 1 <= jr) Add(jl, jr, v, mid + 1, r, i << 1 | 1);
            up(i);
        }
    }
    
    int query(int jl, int jr, int l, int r, int i) {
        if (jl <= l && r <= jr) return maxn[i];
        int mid = (l + r) >> 1;
        down(i);
        int ans = INT_MIN;
        if (jl <= mid) ans = max(ans, query(jl, jr, l, mid, i << 1));
        if (mid + 1 <= jr) ans = max(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
        return ans;
    }
    
    pair<int, int> query_max_with_index(int jl, int jr, int l, int r, int i) {
        if (jl <= l && r <= jr) return {maxn[i], max_idx[i]};
        int mid = (l + r) >> 1;
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
    
    pair<int, int> MaxWithIndex(int l, int r) {
        return query_max_with_index(l, r, 0, arr.size() - 1, 1);
    }
    
    int MaxIndex(int l, int r) {
        return MaxWithIndex(l, r).second;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int res = n & 1 ? n - 1 : n - 2;

    vector<int> b0(n);
    for (int i = 0; i < n; i++) {
        int idx = i + 1;
        if (idx % 2 == 0) b0[i] = 2 * a[idx] + idx;
        else b0[i] = inf;
    }
    SegTree seg0(b0);

    vector<int> b1(n);
    for (int i = 0; i < n; i++) {
        int idx = i + 1;
        if (idx % 2 == 1) b1[i] = -(2 * a[idx] - idx);
        else b1[i] = inf;
    }
    SegTree seg1(b1);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            int val = seg0.Max(i - 1, n - 1);
            if (val > inf / 2)
                res = max(res, val - 2 * a[i] - i);
        } else if (i < n) {
            int val = seg1.Max(i - 1, n - 1);
            if (val > inf / 2)
                res = max(res, val + 2 * a[i] - i);
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) sum += a[i];
        else sum -= a[i];
    }
    cout << sum + res << "\n";
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
