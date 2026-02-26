// Problem: F. Rae Taylor and Trees (hard version)
// Contest: Codeforces - Codeforces Round 1065 (Div. 3)
// URL: https://codeforces.com/contest/2171/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<array<int,2>> edge;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	set<int> st(a.begin()+1,a.end());
	set<int> res;
	for(int i=1;i<=n;i++) {
		if (st.count(a[i]) == 0) {
			res.erase(a[i]);
			continue;
		}
		st.erase(a[i]);
		
		auto it=res.upper_bound(a[i]);
		if (it != res.end()) edge.push_back({a[i],*it});
		
		it=st.upper_bound(a[i]);
		while (it != st.end()) {
			edge.push_back({a[i],*it});
			res.insert(*it);
			st.erase(it);
			it=st.upper_bound(a[i]);
		}
	}
	
	if (edge.size() != n-1) cout<<"No\n";
	else {
		cout<<"Yes\n";
		for(auto [e1,e2] : edge) {
			cout<<e1<<" "<<e2<<"\n";
		}
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







