// Problem: D. 与或博弈
// Contest: Codeforces - The 2025 Shanghai Collegiate Programming Contest
// URL: https://codeforces.com/gym/105992/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	int f1=1,f2=1;
	for(int i=0;i<=61;i++) {
		if (((a>>i)&1) < ((x>>i)&1)) f1=0;
		if (((b>>i)&1) > ((y>>i)&1)) f2=0;
	}
	if (f1 and b == y or f2 and a == x) cout<<"Yes\n";
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







