// Problem: C. XOR and Triangle
// Contest: Codeforces - Codeforces Round 1009 (Div. 3)
// URL: https://mirror.codeforces.com/contest/2074/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
// #define int long long
using namespace std;

int NP(int num)
{
	if(num <= 0) return 1;
	num--;
	num|=num>>1;
	num|=num>>2;
	num|=num>>4;
	num|=num>>8;
	num|=num>>16;
	return num+1;
}

void solve()
{
	int n;
	cin>>n;
	if (n <= 4 or n == NP(n) or n+1 == NP(n)) {cout<<"-1\n";return;}
	int n1=n;
	int ans=0;
	for(int i=0;n1!=0;i++) {
		ans+=((1-(n1&1))<<i);
		n1>>=1;
	}
	for(int i=ans;i<n;i++) {
		int num=(i^n);
		if (i+n > num and i+num > n and num+n > i) {cout<<i<<endl;break;}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









