// Problem: C. Meximum Array 2
// Contest: Codeforces - Codeforces Round 1066 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2157/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k,q;
	cin>>n>>k>>q;
	
	vector<array<int,2>> a;
	vector<array<int,2>> b;
	for(int i=0;i<q;i++) {
		int c,l,r;
		cin>>c>>l>>r;
		if (c == 1) a.push_back({l,r});
		else b.push_back({l,r});
	}
	
	vector<bool> mark(n+1);
	for(auto [l,r] : a) {
		for(int i=l;i<=r;i++) {
			mark[i]=1;
		}
	}
	
	vector<int> ans(n+1,k+1);
	ranges::sort(b);
	for(auto [l,r] : b) {
		vector<int> vec(k);
		for(int i=l;i<=r;i++) {
			if (ans[i] == k+1) continue;
			vec[ans[i]]++;
		}
		vector<int> v;
		for(int i=0;i<k;i++) {
			if (vec[i] == 0) v.push_back(i);
		}
		for(int i=l;!v.empty();i++) {
			if (ans[i] == k+1 and !mark[i]) ans[i]=v.back(),v.pop_back();
		}
	}
	
	vector<int> m(n+1);
	for(auto [l,r] : b) {
		for(int i=l;i<=r;i++) {
			m[i]=1;
		}
	}
	
	for(auto [l,r] : a) {
		for(int i=l;i<=r;i++) {
			if (ans[i] == k+1 and !m[i]) {ans[i]=k;break;}
		}
	}
	
	for(int i=1;i<=n;i++) {
		cout<<ans[i]<<" ";
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







