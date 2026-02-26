// Problem: B. Buses
// Contest: Codeforces - 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/problemset/problem/2172/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,m,l,x,y;
	cin>>n>>m>>l>>x>>y;
	vector<pair<double,int>> b(n);//{t,st}
	for(int i=0;i<n;i++) {
		int st,ed;
		cin>>st>>ed;
		double t=(double)(l-ed)/y+(double)(ed-st)/x;
		b[i]={t,st};
	}
	ranges::sort(b);
	
	vector<array<int,2>> a(m);
	for(int i=0;i<m;i++) {
		int p;
		cin>>p;
		a[i]={p,i};
	}
	ranges::sort(a,greater<array<int,2>>());
	
	vector<double> ans(m);
	int pos=0;
	for(int i=0;i<m;i++) ans[a[i][1]]=(double)(l-a[i][0])/y;
	for(int i=0;i<n;i++) {
		auto [t,st]=b[i];
		while (pos != m and st <= a[pos][0]) {
			ans[a[pos][1]]=min(ans[a[pos][1]],t);
			pos++;
		}
		if (pos == m) break;
	}
	for(auto e1 : ans) cout<<fixed<<setprecision(10)<<e1<<"\n";
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







