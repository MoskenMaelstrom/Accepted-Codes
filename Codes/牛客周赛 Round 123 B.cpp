// Problem: 小红作弊
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125954/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	vector<int> a(13);
	vector<int> b(13);
	for(int i=0;i<13;i++) cin>>a[i];
	for(int i=0;i<13;i++) cin>>b[i];
	
	int ans=0;
	for(int i=0;i<13;i++) {
		ans+=abs(4-a[i]-b[i]);
	}
	cout<<ans/2;
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







