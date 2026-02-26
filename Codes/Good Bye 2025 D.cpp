// Problem: D. Xmas or Hysteria
// Contest: Codeforces - Good Bye 2025
// URL: https://codeforces.com/contest/2178/problem/D
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
	int n,m;
	cin>>n>>m;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i][0];
		a[i][1]=i+1;
	}
	ranges::sort(a);
	
	int lo=1;
	int hi=n/2;
	
	if (m == 0) {
		vector<array<int,2>> ans;
		int p=n-2;
		int sum=0;
		while (p >= 0) {
			sum+=a[p][0];
			ans.push_back({a[p][1],a[n-1][1]});
			if (sum >= a[n-1][0]) break;
			p--;
		}
		if (sum < a[n-1][0]) cout<<"-1\n";
		else {
			cout<<ans.size()+p<<"\n";
			for(int i=0;i<p;i++) {
				cout<<a[i][1]<<" "<<a[i+1][1]<<"\n";
			}
			for(auto [e1,e2] : ans) cout<<e1<<" "<<e2<<"\n";
		}
		return;
	}
	
	if (m < lo or m > hi) {cout<<"-1\n";return;}
	
	vector<array<int,2>> ans;
	for(int i=0;i<n-1;i++) {
		ans.push_back({a[i][1],a[i+1][1]});
	}
	swap(ans[n-2][0],ans[n-2][1]);
	
	int t=m-1;
	int p=ans.size()-1;
	int cnt=ans.size();
	while (t--) {
		p--;
		ans[p]={-1,-1};
		p--;
		swap(ans[p][0],ans[p][1]);
		cnt--;
	}
	
	cout<<cnt<<"\n";
	for(auto [e1,e2] : ans) {
		if (e1 == -1 and e2 == -1) continue;
		cout<<e1<<" "<<e2<<"\n";
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







