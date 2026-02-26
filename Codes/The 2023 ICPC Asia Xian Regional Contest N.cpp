// Problem: G. An Easy Math Problem
// Contest: Codeforces - The 2023 ICPC Asia Xian Regional Contest (The 3rd Universal Cup. Stage 9: Xian)
// URL: https://codeforces.com/gym/105471/problem/G
// Memory Limit: 128 MB
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
	int n;
	cin>>n;
	
	int ans=1;
	int x=2;
	while (x*x <= n) {
		if (n%x != 0) {x++;continue;}
		int cnt=0;
		while (n%x == 0) {
			cnt++;
			n/=x;
		}
		ans*=cnt*2+1;
		x++;
	}
	if (n > 1) ans*=3;
	cout<<(ans+1)/2<<"\n";
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









