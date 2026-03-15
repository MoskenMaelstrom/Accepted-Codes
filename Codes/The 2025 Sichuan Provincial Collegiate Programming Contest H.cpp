// Problem: H. Hututu
// Contest: Codeforces - The 2025 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105949/problem/H
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int x,y,X,Y;
	cin>>x>>y>>X>>Y;
	int c1=abs(x-X)+1>>1;
	int c2=abs(y-Y)+1>>1;
	int ans=max(c1,c2);
	if (abs(x-X) == 0 or abs(y-Y) == 0) ans=max(2ll,ans);
	if (abs(x-X) == 0 and abs(y-Y) == 0) ans=0;
	cout<<ans<<"\n";
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







