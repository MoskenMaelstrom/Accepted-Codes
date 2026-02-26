// Problem: E. Exquisite Array
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/E
// Memory Limit: 256 MB
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
	
	vector<int> d(n-1);
	vector<vector<int>> tong(n+1);
	for(int i=0;i<n-1;i++) {
		d[i]=abs(a[i]-a[i+1]);
		tong[d[i]].push_back(i+1);
	}
	
	int ans=n*(n-1)/2;
	set<int> st;
	st.insert(0);
	st.insert(n);
	for(int i=1;i<n;i++) {
		cout<<ans<<" ";
		for(auto id : tong[i]) {
			int r=*st.upper_bound(id);
			int l=*(--st.upper_bound(id));
			ans-=(r-l-1)*(r-l)/2;
			ans+=(id-l-1)*(id-l)/2+(r-id-1)*(r-id)/2;
			st.insert(id);
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







