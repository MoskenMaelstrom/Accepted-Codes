// Problem: AND vs MEX
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/I
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
	int l,r;
	cin>>l>>r;
	int x=__lg(l),y=__lg(r);
	if (l == 0 or y >= x+2) {cout<<r+1<<"\n";return;}
	if (x == y) {cout<<0<<"\n";return;}
	
	int cnt=(r-(1ll<<y))+1;
	int res=0;
	for(int i=x;i>=0;i--) {
		if ((l>>i)&1) res+=1ll<<i;
		else break;
	}
	if (res <= cnt) cout<<r+1<<"\n";
	else cout<<cnt<<"\n";
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







