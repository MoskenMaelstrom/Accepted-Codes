// Problem: Bitwise Perfect
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108299/B
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
	bool ok=1;
	
	if (n < 64) {
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if ((a[i]^a[j]) <= (max(a[i],a[j]))) ok=0;
			}
		}
	}
	else {
		ok=0;
	}
	
	if (ok) cout<<"YES\n";
	else cout<<"NO\n";
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









