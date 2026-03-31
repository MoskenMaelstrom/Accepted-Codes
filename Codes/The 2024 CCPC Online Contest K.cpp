#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	int x=1;
	while (n%(x<<1) == 0) x<<=1;
	if (x <= k) cout<<"Alice\n";
	else cout<<"Bob\n";
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







