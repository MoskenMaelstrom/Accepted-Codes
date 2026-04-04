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
	int i=1;
	while (i <= n) {
		int d=(i+k-2)/(k-1);
		int maxn=d*(k-1);
		int cnt=(maxn-i)/d;
		if (cnt == 0) cnt=1;
		if (i+cnt*d > n) {
			i+=((n-i)/d)*d;
			break;
		}
		i+=cnt*d;
	}
	cout<<i<<endl;
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







