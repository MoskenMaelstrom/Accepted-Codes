// Problem: B. Team Training
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/contest/2091/problem/B
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	if (k == 1) {cout<<n<<endl;return;}
	ranges::sort(a);
	ranges::reverse(a);
	int cnt=1;
	int ans=0;
	for(int i=0;i<n;i++) {
		if (a[i]*cnt >= k) {
			cnt=1;
			ans++;
		}x
		else cnt++;
	}
	cout<<ans<<endl;
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









