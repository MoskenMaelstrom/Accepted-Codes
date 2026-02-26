// Problem: C1. Hacking Numbers (Easy Version)
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/C1
// Memory Limit: 256 MB
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
using namespace std;


void solve()
{
	int n,o;
	cin>>n;
	cout<<"mul 3"<<endl;
	cin>>o;
	cout<<"digit"<<endl;
	cin>>o;
	cout<<"digit"<<endl;
	cin>>o;
	cout<<"digit"<<endl;
	cin>>o;
	
	cout<<"add -3"<<endl;
	cin>>o;
	if (o == 0) {
		cout<<"add -2"<<endl;
		cin>>o;
		cout<<"add "<<n-1<<endl;
		cin>>o;
		cout<<"!"<<endl;
		cin>>o;
	}
	else {
		cout<<"add -3"<<endl;
		cin>>o;
		cout<<"add "<<n-3<<endl;
		cin>>o;
		cout<<"!"<<endl;
		cin>>o;
	}
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









