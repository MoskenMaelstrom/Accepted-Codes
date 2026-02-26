// Problem: 构造部落
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/B
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,q,s;
	cin>>n>>q>>s;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=s;
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	
	for(int i=0;i<q;i++) {
		int x,y;
		cin>>x>>y;
		y--;
		cout<<a[x-1]+y<<"\n";
	}
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







