// Problem: L. Good Matrix
// Contest: Codeforces - The 18th Jilin Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105922/problem/L
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) (res*=base)%=p;
		(base*=base)%=p;
	}
	return res;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	if (n%2 == 0 and m%2 == 0) cout<<1<<"\n";
	else if (n%2 and m%2) cout<<Pow(2,n+m-2)<<"\n";
	else if (n%2 == 0) cout<<Pow(2,n-1)<<"\n";
	else cout<<Pow(2,m-1)<<"\n";
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







