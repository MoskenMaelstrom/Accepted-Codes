// Problem: C. Simple Repetition
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/C
// Memory Limit: 256 MB
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

bool isp(int n) {
    if (n < 2) return 0;
    for (int i=2;i*i<=n;i++) {
        if (n%i == 0) return 0;
    }
    return 1;
}

void solve()
{
	int x,k;
	cin>>x>>k;
	if (x == 1 and k == 2) cout<<"YES\n";
	else if (k == 1 and isp(x)) cout<<"YES\n";
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









