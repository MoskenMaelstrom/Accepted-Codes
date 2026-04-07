#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<array<int,3>> a(n);
	int sum=0;
	int ans=0;
	for(int i=0;i<n;i++) {
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		sum+=a[i][0];
		ans+=a[i][1];
	}
	ranges::sort(a,[&](array<int,3> X,array<int,3> Y) {
		return (i128)X[2]*Y[0] < (i128)Y[2]*X[0];
	});

	for(int i=n-1;i>=0;i--) {
		sum-=a[i][0];
		ans-=a[i][2]*sum;
	}
	cout<<ans;
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







