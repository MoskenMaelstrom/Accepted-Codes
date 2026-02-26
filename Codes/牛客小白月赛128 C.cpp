// Problem: 左右左右左左右，左右左左右
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127265/C
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
	int n,a0,a1;
	cin>>n>>a1>>a0;
	int c0=0,c1=0;
	for(int i=0;i<n;i++) {
		int d0=abs((c0+1)*a0-(c1)*a1);
		int d1=abs((c0)*a0-(c1+1)*a1);
		if (d0 < d1) c0++,cout<<0;
		else c1++,cout<<1;
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







