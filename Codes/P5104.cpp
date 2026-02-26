// Problem: P5104 红包发红包
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5104
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p=1e9+7;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res=res*base%p;
		base=base*base%p;
	}
	return res;
}

int ny(int num) {
	return Pow(num,p-2);
}

void solve()
{
	int w,n,k;
	cin>>w>>n>>k;
	int base=2;
	for(;k;k>>=1) {
		if (k&1) w*=ny(base),w%=p;
		base*=base,base%=p;
	}
	cout<<w;
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







