// Problem: E. Elevator II
// Contest: Codeforces - The 2024 ICPC Asia Hangzhou Regional Contest (The 3rd Universal Cup. Stage 25: Hangzhou)
// URL: https://codeforces.com/gym/105657/problem/E
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

void solve()
{
	int n,f;
	cin>>n>>f;
	vector<array<int,3>> a(n);
	for(int i=0;i<n;i++) {
		int l,r;
		cin>>l>>r;
		a[i]={l,r,i};
	}
	ranges::sort(a);
	int ans=0;
	vector<int> vec1,vec2;
	for(auto [l,r,id] : a) {
		ans+=r-l;
		if (r > f) {
			vec1.push_back(id);
			ans+=max(0ll,l-f);
			f=r;
		}
		else vec2.push_back(id);
	}
	cout<<ans<<"\n";
	ranges::reverse(vec2);
	for(auto i : vec1) cout<<i+1<<" ";
	for(auto i : vec2) cout<<i+1<<" ";
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







