// Problem: B. Maximum Cost Permutation
// Contest: Codeforces - Educational Codeforces Round 182 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2144/problem/B
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

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt=ranges::count(a,0);
	if (cnt == 1) {
		set<int> st;
		for(int i=1;i<=n;i++) st.insert(i);
		for(int i=0;i<n;i++) if (a[i] != 0) st.erase(a[i]);
		for(int i=0;i<n;i++) {
			if (a[i] == 0) a[i]=*st.begin();
		}
	}
		int l=0,r=-1;
		for(int i=0;i<n;i++) {
			if (a[i] != i+1 or a[i] == 0) {l=i;break;}
		}
		for(int i=n-1;i>=0;i--) {
			if (a[i] != i+1 or a[i] == 0) {r=i;break;}
		}
		cout<<r-l+1<<"\n";
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









