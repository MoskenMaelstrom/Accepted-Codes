// Problem: H. GG and YY's Stone Game
// Contest: Codeforces - The 2024 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105222/problem/H
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

void solve()
{
	int n;
	cin>>n;
	if ((n-1)%3 == 2) cout<<"1 "<<n/3<<"\n";
	else if ((n-1)%3 == 1) cout<<"0 "<<n/3+2<<"\n";
	else cout<<"0 "<<n/3+1<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







