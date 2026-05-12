// Problem: G. 精确的浪漫
// Contest: Codeforces - The 9th Hebei Collegiate Programming Contest
// URL: https://codeforces.com/gym/105909/problem/G
// Memory Limit: 1024 MB
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
	int sx,sy,tx,ty,x,y;
	cin>>sx>>sy>>tx>>ty>>x>>y;
	string s;
	
	while (x != 0) {
		sy--;
		s+="S";
		x/=2;
	}
	
	if (sx < tx) s+=string(tx-sx,'D');
	else s+=string(sx-tx,'A');
	x+=tx-sx;
	
	while (x != 0) {
		sy--;
		s+="S";
		x/=2;
	}
	if (sy < ty) s+=string(ty-sy,'W');
	else s+=string(sy-ty,'S');
	// cout<<s<<"\n";
	
	s+=string(__builtin_popcountll(y),'A');
	s+=string(__lg(y)+1,'S');
	for(int i=__lg(y);i>=0;i--) {
		// cout<<x<<" ";
		x*=2,s+='W';
		if ((y>>i)&1) x++,s+='D';
	}
	// cout<<x<<"\n";
	assert(x == y);
	cout<<s<<"\n";
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







