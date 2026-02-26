// Problem: D. Quartet Swapping
// Contest: Codeforces - Codeforces Round 1024 (Div. 2)
// URL: https://codeforces.com/contest/2102/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
class SegTree {
private:
    vector<int> arr;
    vector<int> sum, add, change, mark;
    int n;
    
    void up(int i) {
        sum[i] = sum[i<<1] + sum[i<<1|1];
    }
    
    void down(int i, int ln, int rn) {
        if (mark[i]) {
            Changelazy(i<<1, change[i], ln);
            Changelazy(i<<1|1, change[i], rn);
            mark[i] = 0;
        }
        if (add[i] != 0) {
            Addlazy(i<<1, add[i], ln);
            Addlazy(i<<1|1, add[i], rn);
            add[i] = 0;
        }
    }
    
    void Changelazy(int i, int v, int n) {
        sum[i] = v * n;
        add[i] = 0;
        change[i] = v;
        mark[i] = 1;
    }
    
    void Addlazy(int i, int v, int n) {
        sum[i] += v * n;
        add[i] += v;
    }

    void build(int l, int r, int i) {
        if (l == r) sum[i] = arr[l];
        else {
            int mid = l + r >> 1;
            build(l, mid, i<<1);
            build(mid + 1, r, i<<1|1);
            up(i);
        }
    }
    
    void Change(int jl, int jr, int v, int l, int r, int i) {
        if (jl <= l && r <= jr) Changelazy(i, v, r - l + 1);
        else {
            int mid = l + r >> 1;
            down(i, mid - l + 1, r - mid);
            if (jl <= mid) Change(jl, jr, v, l, mid, i<<1);
            if (mid + 1 <= jr) Change(jl, jr, v, mid + 1, r, i<<1|1);
            up(i); 
        }
    }
    
    void Add(int jl, int jr, int v, int l, int r, int i) {
        if (jl <= l && r <= jr) Addlazy(i, v, r - l + 1);    
        else {
            int mid = l + r >> 1;
            down(i, mid - l + 1, r - mid);
            if (jl <= mid) Add(jl, jr, v, l, mid, i<<1);
            if (mid + 1 <= jr) Add(jl, jr, v, mid + 1, r, i<<1|1);
            up(i); 
        }
    }
    
    int query(int jl, int jr, int l, int r, int i) {
        if (jl <= l && r <= jr) return sum[i];
        int mid = l + r >> 1;
        down(i, mid - l + 1, r - mid);
        int ans = 0;
        if (jl <= mid) ans += query(jl, jr, l, mid, i<<1);
        if (mid + 1 <= jr) ans += query(jl, jr, mid + 1, r, i<<1|1);
        return ans;
    }

public:
    SegTree() {}
    
    SegTree(const vector<int>& nums) : arr(nums), n(nums.size()) {
        sum.assign(4 * n, 0);
        add.assign(4 * n, 0);
        change.assign(4 * n, 0);
        mark.assign(4 * n, 0);
        build(0, n - 1, 1);
    }
    
    // 区间修改：将区间[l, r]的值全部改为v
    void rChange(int l, int r, int v) {
        if (l < 0 || r >= n || l > r) return;
        Change(l, r, v, 0, n - 1, 1);
    }
    
    // 区间加法：给区间[l, r]每个元素加上v
    void rAdd(int l, int r, int v) {
        if (l < 0 || r >= n || l > r) return;
        Add(l, r, v, 0, n - 1, 1);
    }
    
    // 区间查询：查询区间[l, r]的和
    int Sum(int l, int r) {
        if (l < 0 || r >= n || l > r) return 0;
        return query(l, r, 0, n - 1, 1);
    }
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a1,a2;
	for(int i=0;i<n;i++) {
		int e1;cin>>e1;
		if (i%2 == 0) a1.push_back(e1);
		else a2.push_back(e1);
	}
	
	
	int cnt1=0;
	vector<int> t1(n+1);
	int n1=a1.size();
	SegTree st1(t1);
	for(int i=n1-2;i>=0;i--) {
		st1.rAdd(a1[i+1],a1[i+1],1);
		cnt1+=st1.Sum(0,a1[i]-1);
	}
	ranges::sort(a1);
	if(cnt1%2 == 1) swap(a1[n1-1],a1[n1-2]);
	
	int cnt2=0;
	vector<int> t2(n+1);
	int n2=a2.size();
	SegTree st2(t2);
	for(int i=n2-2;i>=0;i--) {
		st2.rAdd(a2[i+1],a2[i+1],1);
		cnt2+=st2.Sum(0,a2[i]-1);
	}
	ranges::sort(a2);
	if(cnt2%2 == 1) swap(a2[n2-1],a2[n2-2]);
	
	
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		if (i%2 == 0) a[i]=a1[i/2];
		else a[i]=a2[i/2];
	}
	
	vector<int> b=a;
	swap(a[n-1],a[n-3]);swap(a[n-2],a[n-4]);
	if (b < a) {
		for(int i=0;i<n;i++) cout<<b[i]<<" \n"[i == n-1];
	}
	else {
		for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i == n-1];
	}
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









