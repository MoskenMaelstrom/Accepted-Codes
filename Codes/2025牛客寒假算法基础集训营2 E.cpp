// Problem: 一起走很长的路！
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95334/E
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
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

//ST<int,1> st1(a);
template<typename T, bool isMin>
struct ST {
    int n, m;
    vector<vector<T>> f;
 
    ST() {}
    ST(int n) : n(n), m(__lg(n)), f(m + 1, vector<T>(n)) {}
    ST(const vector<T> &init) : ST((int)init.size()) {
        for(int i = 0; i < n; i++){
            f[0][i] = init[i];
        }
        for(int j = 1; j <= m; j++){
            for(int i = 0; i + (1 << j) - 1 < n; i++) {
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector<int> pre(n);
	pre[0]=a[0];
	for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
	vector<int> b(n);
	for(int i=1;i<n;i++) b[i]=pre[i-1]-a[i];
	ST<int,1> st(b);
	
	while (q--) {
		int l,r;
		cin>>l>>r;
		l--;r--;
		int k=st.query(l+1,r);
		if (l == r) cout<<"0\n";
		else if (l != 0) cout<<max(0ll,pre[l-1]-k)<<endl;
		else cout<<(k < 0 ? -k : 0)<<endl;
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









