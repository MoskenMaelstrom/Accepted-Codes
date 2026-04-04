#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	string a,b;
	cin>>a>>b;
	int n=a.size();
	int m=b.size();
	int ans=0;
	for(int i=0;i<n;i++) {
		int p1=i;
		int p2=0;
		while (p1 < n and p2 < m) {
			if (a[p1] == b[p2]) p2++;
			p1++;
		}
		if (p2 == m) ans+=p1-i-1;
		else ans+=n-i;
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







