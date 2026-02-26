// Problem: 数值膨胀之美
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/M
// Memory Limit: 512 MB
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


template<typename T, bool isMin>
struct SparseTable {
    int n, m;
    vector<vector<T>> f;
 
    SparseTable() {}
    SparseTable(int n) : n(n), m(__lg(n)), f(m + 1, vector<T>(n + 1)) {}
    SparseTable(const vector<T> &init) : SparseTable((int)init.size()) {
        for(int i = 1; i <= n; i++){
            f[0][i] = init[i - 1];
        }
        for(int j = 1; j <= m; j++){
            for(int i = 1; i + (1 << j) - 1 <= n; i++){
                if (isMin) f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
                else f[j][i] = max(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
            }       
        }
    }

    T query(int l, int r) {
        if (l > r){
            if (isMin) return numeric_limits<T>::max() / 10;
            return numeric_limits<T>::min() / 10;
        }
        int len = __lg(r - l + 1);
        if (isMin) return min(f[len][l], f[len][r - (1 << len) + 1]);
        return max(f[len][l], f[len][r - (1 << len) + 1]);        
    }
};

	
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	SparseTable<int,0> st1(a);
	SparseTable<int,1> st2(a);
	
	auto get=[&](int l,int r) -> int {
		int maxx=max({st1.query(l,r)*2,st1.query(1,l-1),st1.query(r+1,n)});
		int minx=min({st2.query(l,r)*2,st2.query(1,l-1),st2.query(r+1,n)});
		return maxx-minx;
	};
	
	vector<int> id(n);
	iota(id.begin(),id.end(),1);
	sort(id.begin(),id.end(),[&](int x,int y) {
		return (a[x-1] < a[y-1]);
	});
	
	int ans=1e18;
	int l=1e9,r=0;
	for(auto e1 : id) {
		l=min(l,e1);
		r=max(r,e1);
		ans=min(ans,get(l,r));
	}
	cout<<ans;
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









