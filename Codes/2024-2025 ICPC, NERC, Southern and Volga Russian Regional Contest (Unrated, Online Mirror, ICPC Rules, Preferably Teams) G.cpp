// Problem: G. Guess One Character
// Contest: Codeforces - 2024-2025 ICPC, NERC, Southern and Volga Russian Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/2038/problem/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int a1,a2,a3;
	cout<<"1 1"<<endl;
	cin>>a1;
	cout<<"1 11"<<endl;
	cin>>a2;
	cout<<"1 10"<<endl;
	cin>>a3;
	if (a1 == a2+a3) cout<<"0 "<<n<<" 0"<<endl;
	else cout<<"0 "<<n<<" 1"<<endl;
	cin>>a1;
	
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









