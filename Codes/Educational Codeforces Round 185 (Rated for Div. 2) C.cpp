// Problem: C. Quotient and Remainder
// Contest: Codeforces - Educational Codeforces Round 185 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2170/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	multiset<int,greater<int>> st;
	for(int i=0;i<n;i++) st.insert(a[i]);
	ranges::sort(b);
	
	int cnt=0;
	for(int i=0;i<n;i++) {
		int y=b[i]+1;
		while (st.size() > 0 and *st.begin()*y+b[i] > k) st.erase(st.begin());
		if (st.size() > 0) cnt++,st.erase(st.begin());
	}
	
	cout<<cnt<<"\n";
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







