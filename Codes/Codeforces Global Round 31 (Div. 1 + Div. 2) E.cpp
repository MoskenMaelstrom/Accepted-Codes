// Problem: E. No Effect XOR
// Contest: Codeforces - Codeforces Global Round 31 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2180/problem/E
// Memory Limit: 256 MB
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
	if ((r-l+1)%2 == 1) {
		cout<<"0\n";
		return;
	}
	
	int b=__lg(l^r);
	int m=r>>b<<b;
	
	int ans=1;
	if (r-m+1 == m-l) ans<<=1; 
	for(int x=1;x<=b;x++) {
		if ((r-m+1)%(1ll<<x) == 0 and (m-l)%(1ll<<x) == 0) ans<<=1;
	}
	
	cout<<ans-1<<"\n";
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







