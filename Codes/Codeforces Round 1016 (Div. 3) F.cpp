// Problem: F. Hackers and Neural Networks
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/F
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

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<string> a(n);
	vector b(m,vector<string>(n));
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) 
		for(int j=0;j<n;j++) cin>>b[i][j];
	
	
	vector<int> cnt(m);
	for(int j=0;j<n;j++) {
		bool ok=0;
		for(int i=0;i<m;i++) {
			if (b[i][j] == a[j]) {ok=1;cnt[i]++;}
		}
		if (!ok) {cout << -1 << endl;return;}
	}
	
	int ans=*ranges::max_element(cnt);
	cout<<n+(n-ans)*2<<endl;
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









