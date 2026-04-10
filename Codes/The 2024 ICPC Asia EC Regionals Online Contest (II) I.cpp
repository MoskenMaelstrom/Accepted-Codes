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

	vector<int> a(32);
	for(int i=31;i>=0;i--) {
		a[i]=(n>>i)&1;
	}
	int cnt=0;
	for(int i=31;i>=0;i--) {
		if (a[i] == 0) cnt++;
		else cnt=0;
	}
	if (cnt >= 2 or n == 0) {cout<<"NO\n";return;}
	for(int i=31;i>=0;i--) {
		if (a[i] == 1) {
			a[i]=-1;
			int p=i+1;
			while (p <= 31 and a[p] == 0) a[p++]=-1;
			a[--p]=1;
		}
	}

	cout<<"YES\n";
	for(int i=0;i<=31;i++) {
		cout<<a[i]<<" ";
		if ((i+1)%8 == 0) cout<<"\n";
	}
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







