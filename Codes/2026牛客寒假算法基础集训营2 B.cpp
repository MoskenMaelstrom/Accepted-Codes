// Problem: NCPC
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/B
// Memory Limit: 2048 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	int x=*ranges::max_element(a);
	if (ranges::count(a,x)&1) {
		for(auto e1 : a) {
			if (e1 == x) cout<<1;
			else cout<<0;
		}
	}
	else {
		for(auto e1 : a) {
			if (e1 != x) cout<<1;
			else cout<<0;
		}
	}
	cout<<"\n";
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







