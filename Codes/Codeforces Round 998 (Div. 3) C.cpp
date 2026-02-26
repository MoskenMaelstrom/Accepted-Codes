#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	int L=0,R=n-1,ans=0;
	while (L < R)
	{
		if (a[L]+a[R] == k) {L++;R--;ans++;}
		else if (a[L]+a[R] < k) L++;
		else R--;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}