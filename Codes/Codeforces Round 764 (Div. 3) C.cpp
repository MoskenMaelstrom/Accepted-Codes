#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> tong(n+1,0);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	for(int i=0;i<n;i++) {
		while (a[i] != 0) {
			if (1 <= a[i] and a[i] <= n and tong[a[i]] == 0) {tong[a[i]]++;break;}
			else a[i]>>=1;
		}
	}
	for(int i=1;i<=n;i++) if (tong[i] == 0) {cout<<"NO\n";return;}
	cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









