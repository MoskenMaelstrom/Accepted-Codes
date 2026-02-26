// Problem: U - Fibonacci Reversed
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/U
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	vector<int> a(11);
	cin>>a[1]>>a[2];
	auto f=[&](int num) {
		int res=0;
		while (num != 0) {
			res=res*10+num%10;
			num/=10;
		}
		return res;
	};
	for(int i=3;i<=10;i++) {
		a[i]=f(a[i-1]+a[i-2]);
	}
	cout<<a[10];
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









