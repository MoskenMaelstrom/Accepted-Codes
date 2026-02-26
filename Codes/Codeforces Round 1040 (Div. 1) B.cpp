// Problem: B. Stay or Mirror
// Contest: Codeforces - Codeforces Round 1040 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2129/B
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

template<typename T>
struct Fenwick{
    int n;
    vector<T> tr;
 
    Fenwick(int n) : n(n), tr(n + 1, 0){}
 
    int lowbit(int x){
        return x & -x;
    }
 
    void modify(int x, T c){
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
 
    void modify(int l, int r, T c){
        modify(l, c);
        if (r + 1 <= n) modify(r + 1, -c);
    }
 
    T query(int x){
        T res = T();
        for(int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
 
    T query(int l, int r){
        return query(r) - query(l - 1);
    }

	// 查找第一个前缀和≥sum的位置
    int find_first(T sum){
        int ans = 0; T val = 0;
        for(int i = __lg(n); i >= 0; i--){
            if ((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] < sum){
                ans |= 1 << i;
                val += tr[ans];
            }
        }
        return ans + 1;
    }
 
	// 查找最后一个前缀和≤sum的位置
    int find_last(T sum){
        int ans = 0; T val = 0;
        for(int i = __lg(n); i >= 0; i--){
            if ((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] <= sum){
                ans |= 1 << i;
                val += tr[ans];
            }
        }
        return ans;
    }
 
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	map<int, int> mp;
	for(int i=1;i<=n;i++) {
		mp[a[i]]=i;
	}
	
	Fenwick<int> fw(n);
	int ans=0;
	for(auto [val,i] : mp) {
		int n1=i-1-fw.query(1,i-1);
		int n2=n-i-fw.query(i+1,n);
		
		if (n1 > n2) a[i]=2*n-a[i],ans+=n2;
		else ans+=n1;
		fw.modify(i,1);
	}
	
	cout<<ans<<"\n";
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









