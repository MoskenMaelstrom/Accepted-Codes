// Problem: A. Once In My Life
// Contest: Codeforces - 2024 National Invitational of CCPC (Zhengzhou), 2024 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105158/problem/A
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

int Pow(int base,int exp) {
	int res=1;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base;
		base*=base;
	}
	return res;
}

void solve()
{
	int n,d;
	cin>>n>>d;
	int N=n;
	int cnt=0;
	while (N) {
		cnt++;
		N/=10;
	}
	int n1=(1234567890+d)*Pow(10,cnt);
	cout<<(n1+n-1)/n<<"\n";
	// cout<<(n1+n-1)/n*n<<"\n";
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







