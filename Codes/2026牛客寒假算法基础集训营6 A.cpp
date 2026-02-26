// Problem: 小L的三角尺
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/A
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
	int n,w;
	cin>>n>>w;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	auto calc=[&](int x,int y) -> double {
		if (y == 0) return 0.0;
		double d=sqrt(x*x+y*y)-sqrt(x*x+(y-1)*(y-1));
		return d;
	};
	
	auto cmp=[&](const array<int,2>& a1,const array<int,2>& a2) {
		return calc(a1[0],a1[1]) < calc(a2[0],a2[1]);
	};
	
	priority_queue<array<int,2>,vector<array<int,2>>,decltype(cmp)> pq(cmp);
	
	for(int i=0;i<n;i++) pq.push({a[i],b[i]});

	double ans=0;
	while (w--) {
		auto [x,y]=pq.top();
		pq.pop();
		y--;
		if (y != 0) pq.push({x,y});
		else ans+=x;
		if (pq.empty()) break;
	}
	
	while (!pq.empty()) {
		auto [x,y]=pq.top();
		pq.pop();
		ans+=sqrt(x*x+y*y);
	}
	cout<<fixed<<setprecision(10)<<ans;
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







