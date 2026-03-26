// Problem: J. Points on the Number Axis A
// Contest: Codeforces - The 2024 International Collegiate Programming Contest in Hubei Province, China
// URL: https://codeforces.com/gym/105139/problem/J
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

const int p=998244353;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

int Inv(int num) {
	return Pow(num,p-2);
}

void solve()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		(sum+=x)%=p;
	}
	cout<<sum*Inv(n)%p;
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







