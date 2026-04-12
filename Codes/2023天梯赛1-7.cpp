#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n0,n1,n;
	cin>>n0>>n1>>n;
	int a0=0,a1=1e18;
	bool ok=0;
	for(int i=1;i<=n0/i;i++) {
		if (n0%i) continue;
		for(int j=1;j<=n1/j;j++) {
			if (n1%j) continue;
			if (n0/i+n1/j == n and i != 1 and j != 1) {
				ok=1;
				if (abs(i-j) < abs(a0-a1)) a0=i,a1=j;
			}
			if (n0/i+n1/(n1/j) == n and i != 1 and n1/j != 1) {
				ok=1;
				if (abs(i-n1/j) < abs(a0-a1)) a0=i,a1=n1/j;
			}
			if (n0/(n0/i)+n1/j == n and n0/i != 1 and j != 1) {
				ok=1;
				if (abs(n0/i-j) < abs(a0-a1)) a0=n0/i,a1=j;
			}
			if (n0/(n0/i)+n1/(n1/j) == n and n0/i != 1 and n1/j != 1) {
				ok=1;
				if (abs(n0/i-n1/j) < abs(a0-a1)) a0=n0/i,a1=n1/j;
			}
		}
	}
	if (!ok) {cout<<"No Solution";return;}
	cout<<n0/a0<<" "<<n1/a1;
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