// Problem: C. Bewitching Stargazer
// Contest: Codeforces - Good Bye 2024: 2025 is NEAR
// URL: https://codeforces.com/problemset/problem/2053/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

int n,k;
array<int,2> work(int l,int r)
{
	int cost;
	int cnt;
	if (r-l+1 < k) return {0,0};
	if ((r-l+1)%2) {
		auto [e1,e2]=work(l,(l+r)/2-1);
		cost=2*e1 + e2*((l+r)/2+1-l) + ((l+r)/2);
		cnt=1+e2*2;
	}
	else {
		auto [e1,e2]=work(l,(l+r)/2);
		cost=2*e1 + e2*((l+r)/2+1-l);
		cnt=e2*2;
	}
	return {cost,cnt};
}
void solve()
{
	cin>>n>>k;
	auto [e1,e2]=work(1,n);
	cout<<e1<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









