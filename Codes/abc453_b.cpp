#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,x;
	cin>>n>>x;
	int a;
	cin>>a;
	cout<<0<<" "<<a<<"\n";
	for(int i=1;i<=n;i++) {
		int cur;
		cin>>cur;
		if (abs(cur-a) >= x) {
			cout<<i<<" "<<cur<<"\n";
			a=cur;
		}
	}
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







