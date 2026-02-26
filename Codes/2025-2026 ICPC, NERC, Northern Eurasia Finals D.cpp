// Problem: D. Doorway
// Contest: Codeforces - 2025-2026 ICPC, NERC, Northern Eurasia Finals (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/2181/D
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	multiset<int> st;
	vector<array<int,3>> vec;
	for(int i=0;i<n;i++) {
		int k,l,r;
		cin>>k>>l>>r;
		int sum=0;
		vector<int> a(k);
		for(int j=0;j<k;j++) {
			cin>>a[j];
			sum+=a[j];
		}
		
		st.insert(l);
		int pre=0;
		for(int j=0;j<k;j++) {
			vec.push_back({r-(sum-pre),l+pre,l+pre+a[j]});
			pre+=a[j];
		}
		vec.push_back({r,l+sum,inf});
	}
	ranges::sort(vec);
	
	int ans=0;
	for(auto [r,l1,l2] : vec) {
		ans=max(ans,r-*st.rbegin());
		st.extract(l1);
		st.insert(l2);
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







