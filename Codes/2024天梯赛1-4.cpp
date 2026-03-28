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
	int sum=0;
	for(int i=0;i<m;i++) {
		int x;
		cin>>x;
		sum+=x;
	}
	cout<<max(0ll,sum-n*(m-1));
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







