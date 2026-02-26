// Problem: C. Trip to the Olympiad
// Contest: Codeforces - Hello 2025
// URL: https://codeforces.com/contest/2057/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
int max1(int n)
{
	int t=0;
	while (n != 0) {n>>=1;t++;}
	return t;
}
void solve()
{
	int l,r,a,b,c;
	cin>>l>>r;
	int k=max1(l^r);//r和l第一个不同的位数
	b=((r>>k)<<k) + (1<<(k-1)) - 1;
	if (b != l) a=b+1,c=b-1;
	else a=b+1,c=b+2;
	
	cout<<a<<" "<<b<<" "<<c<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}