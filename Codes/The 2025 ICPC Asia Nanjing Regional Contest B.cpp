#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

void solve()
{
	int n;
	cin>>n;
	map<double,int> mp;
	int cur=0;
	for(int i=0;i<n;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		if (a == 0 and b == 0) continue;
		double s=atan2l(a,-b);
		double t=atan2l(-a,b);
		mp[s]++;
		mp[t]--;
		if (s > t) cur++;
	}
	int ans=cur;
	for(auto [e1,cnt] : mp) {
		cur+=cnt;
		ans=max(ans,cur);
	}
	cout<<ans<<"\n";
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







