// Problem: L. LCMs
// Contest: Codeforces - The 2024 International Collegiate Programming Contest in Hubei Province, China
// URL: https://codeforces.com/gym/105139/problem/L
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int a,b;
	cin>>a>>b;
	auto d=[&](int x,int y) -> int {
		if (x == y) return 0;
		if (x%y == 0) return x;
		if (y%x == 0) return y;
		if (gcd(x,y) != 1) return x+y;
		return min(x*y,2*x+2*y);
	};
	
	int p1=a,p2=b;
	for(int i=2;i<=a/i;i++) {
		if (a%i == 0) {p1=i;break;}
	}
	for(int i=2;i<=b/i;i++) {
		if (b%i == 0) {p2=i;break;}
	}
	
	cout<<min(d(a,b),d(a,p1)+d(p1,p2)+d(p2,b))<<"\n";
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







