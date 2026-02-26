// Problem: F - Pyramid Alignment
// Contest: AtCoder - AtCoder Beginner Contest 428
// URL: https://atcoder.jp/contests/abc428/tasks/abc428_f
// Memory Limit: 1024 MB
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
    int n;
    vector<int> t, s, a;
    SegTree(vector<int> &arr) {
        n = arr.size();
        t.resize(4 * n);
        s.assign(4 * n, INT_MIN);
        a.resize(4 * n);
        build(1, 0, n - 1, arr);
    }
    void build(int v, int l, int r, vector<int> &arr) {
        if (l == r) { t[v] = arr[l]; return; }
        int m = (l + r) / 2;
        build(2 * v, l, m, arr);
        build(2 * v + 1, m + 1, r, arr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void push(int v, int l, int r) {
        if (s[v] != INT_MIN) {
            t[v] = s[v] * (r - l + 1);
            if (l != r) {
                s[2 * v] = s[v]; a[2 * v] = 0;
                s[2 * v + 1] = s[v]; a[2 * v + 1] = 0;
            }
            s[v] = INT_MIN;
        }
        if (a[v] != 0) {
            t[v] += a[v] * (r - l + 1);
            if (l != r) {
                a[2 * v] += a[v];
                a[2 * v + 1] += a[v];
            }
            a[v] = 0;
        }
    }
    void update_set(int v, int l, int r, int ql, int qr, int val) {
        push(v, l, r);
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            s[v] = val; a[v] = 0;
            push(v, l, r);
            return;
        }
        int m = (l + r) / 2;
        update_set(2 * v, l, m, ql, qr, val);
        update_set(2 * v + 1, m + 1, r, ql, qr, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void update_add(int v, int l, int r, int ql, int qr, int val) {
        push(v, l, r);
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            a[v] += val;
            push(v, l, r);
            return;
        }
        int m = (l + r) / 2;
        update_add(2 * v, l, m, ql, qr, val);
        update_add(2 * v + 1, m + 1, r, ql, qr, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    int query(int v, int l, int r, int pos) {
        push(v, l, r);
        if (l == r) return t[v];
        int m = (l + r) / 2;
        if (pos <= m) return query(2 * v, l, m, pos);
        else return query(2 * v + 1, m + 1, r, pos);
    }
    void update_set(int l, int r, int val) { update_set(1, 0, n - 1, l, r, val); }
    void update_add(int l, int r, int val) { update_add(1, 0, n - 1, l, r, val); }
    int query(int pos) { return query(1, 0, n - 1, pos); }
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> vec1(n+1,0),vec2(n+1,-1);
	SegTree L(vec1);
	SegTree R(vec2);
	
	int q;
	cin>>q;
	while (q--) {
		int o,idx;
		cin>>o>>idx;
		
		if (o == 1) {
			int d=(L.query(idx) != -1 ? L.query(idx) : R.query(idx)-a[idx]);
			// cout<<"d:"<<d<<endl;
			L.update_set(1,idx,d);
			R.update_set(1,idx,-1);
		}
		else if (o == 2) {
			int d=(R.query(idx) != -1 ? R.query(idx) : L.query(idx)+a[idx]);
			// cout<<"d:"<<d<<endl;
			L.update_set(1,idx,-1);
			R.update_set(1,idx,d);
		}
		else {
			int l=idx,r=idx+1;
			// for(int i=1;i<=n;i++) cout<<L.query(i)<<" "<<R.query(i)<<endl;
			
			int lo=1,hi=n,idx1=-1;
			while (lo <= hi) {
				int mid=lo+hi>>1;
				int d=(L.query(mid) != -1 ? L.query(mid) : R.query(mid)-a[mid]);
				if (d <= l) idx1=mid,hi=mid-1;
				else lo=mid+1;
			}
			if (idx1 == -1) {cout<<"0\n";continue;}
			
			lo=idx1,hi=n;
			int idx2=-1;
			while (lo <= hi) {
				int mid=lo+hi>>1;
				int d=(R.query(mid) != -1 ? R.query(mid) : L.query(mid)+a[mid]);
				if (d >= r) idx2=mid,hi=mid-1;
				else lo=mid+1;
			}
			if (idx2 == -1) {cout<<"0\n";continue;}
			
			cout<<n-idx2+1<<"\n";
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









