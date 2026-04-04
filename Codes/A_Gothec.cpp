#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	bool ok=0;
	if (n == 1 and m == 7) ok=1;
	if (n == 3 and m == 3) ok=1;
	if (n == 5 and m == 5) ok=1;
	if (n == 7 and m == 7) ok=1;
	if (n == 9 and m == 9) ok=1;

	if (ok) cout<<"Yes\n";
	else cout<<"No\n";
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







