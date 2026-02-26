// Problem: D. Counting Points
// Contest: Codeforces - Codeforces Round 1009 (Div. 3)
// URL: https://codeforces.com/contest/2074/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

int floorSqrt(int x)
{
	int num=sqrt(x);
	if (num*num > x) num--;
	return num;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,2>> a;
	vector<int> x(n),r(n);
	for(auto &e1 : x) cin>>e1;
	for(auto &e1 : r) cin>>e1;
	for(int i=0;i<n;i++) {
		for(int j=-r[i];j<=r[i];j++) {
			int y=floorSqrt(r[i]*r[i]-j*j);
			a.push_back({j+x[i],y});
		}
	}
	ranges::sort(a);
	int ans=0;
	for(int l=0,r=0;l<a.size();l=r) {
		while (r < a.size() and a[l][0] == a[r][0]) r++;
		int y=0;
		for(int i=l;i<r;i++) {
			y=max(y,a[i][1]);
		}
		ans+=2*y+1;
	}
	cout<<ans<<endl;
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









