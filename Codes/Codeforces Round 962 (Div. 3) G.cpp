// Problem: G. Penacony
// Contest: Codeforces - Codeforces Round 962 (Div. 3)
// URL: https://codeforces.com/contest/1996/problem/G
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<u64> f(n);
	for(int i=0;i<m;i++) {
		int n1,n2;
		cin>>n1>>n2;
		n1--,n2--;
		u64 x=rng();
		f[n1]^=x;
		f[n2]^=x;
	}
	for(int i=1;i<n;i++) f[i]^=f[i-1];
	
	map<u64,int> cnt;
	for(int i=0;i<n;i++) cnt[f[i]]++;
	
	int ans=0;
	for(auto [e1,e2] : cnt) ans=max(ans,e2);
		
	cout<<n-ans<<"\n";
	
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









