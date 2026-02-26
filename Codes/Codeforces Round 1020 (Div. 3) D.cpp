// Problem: D. Flower Boy
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2106/D
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

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	
	vector<int> l(n,-1),r(n,-1);
	int bi=0;
	for(int i=0;i<n;i++) {
		if (bi < m and b[bi] <= a[i]) bi++;
		l[i]=bi;
	}
	bi=m-1;
	for(int i=n-1;i>=0;i--) {
		if (bi >= 0 and b[bi] <= a[i]) bi--;
		r[i]=bi;
	}
	
	if (l[n-1] == m) cout<<"0\n";
	else {
		int res=inf;
		if (l[n-1] == m-1) res=min(res,b[m-1]);
		if (r[0] == 0) res=min(res,b[0]);
		for(int i=0;i<n-1;i++) {
			if (l[i] == r[i+1]) res=min(res,b[l[i]]);
		}
		cout<<(res == inf ? -1 : res)<<"\n";
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









