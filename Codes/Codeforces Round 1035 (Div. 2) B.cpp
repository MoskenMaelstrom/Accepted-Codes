// Problem: B. Line Segments
// Contest: Codeforces - Codeforces Round 1035 (Div. 2)
// URL: https://codeforces.com/contest/2119/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	double dis=sqrt(abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2));
	ranges::sort(a);
	int maxn=0;
	for(int i=0;i<n;i++) maxn+=a[i];
	int minn=2*a[n-1]-maxn;
	if (minn<=dis and dis<=maxn) cout<<"Yes\n";
	else cout<<"No\n";
	
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









