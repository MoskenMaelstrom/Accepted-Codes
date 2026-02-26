// Problem: B. Discounts
// Contest: Codeforces - Codeforces Round 1051 (Div. 2)
// URL: https://codeforces.com/contest/2143/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n,k;
	cin>>n>>k;
	int ans=0;
	vector<int> a(n);
	vector<int> b(k);
	for(int i=0;i<n;i++) {cin>>a[i];ans+=a[i];}
	for(int i=0;i<k;i++) cin>>b[i];
	ranges::sort(a,greater<int>());
	ranges::sort(b);
	int p=0,idx=0;
	while (p != n) {
		if (idx == k) break;
		if (p+b[idx] > n) break;
		p+=b[idx];
		ans-=a[p-1];
		idx++;
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









