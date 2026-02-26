// Problem: P1890 gcd区间
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1890
// Memory Limit: 125 MB
// Time Limit: 1000 ms
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

//ST st(n,arr);
const int B = 19;
struct ST {
    #define lg2(n) (63 - __builtin_clzll((long long)(n)))
    int n;
    vector<vector<int>> st;
    ST (int n, vector<int> &a): n(n) {
        st.assign(B, vector<int>(n, 0));
        for (int i = 0; i < n; i++) st[0][i] = a[i];

        for (int j = 1; j < B; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {  // 改为从0开始
                st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int k = lg2(r - l + 1);
        return gcd(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	ST st(n,a);
	while (m--) {
		int l,r;
		cin>>l>>r;
		cout<<st.query(l-1,r-1)<<endl;
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









