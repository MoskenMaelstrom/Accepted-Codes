// Problem: B. Vicious Labyrinth
// Contest: Codeforces - Codeforces Round 1008 (Div. 2)
// URL: https://mirror.codeforces.com/contest/2078/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	if (n == 2) {cout<<"2 1\n";return;}
	if (k%2 == 1) {
		for(int i=0;i<n-1;i++) cout<<n<<" ";
		cout<<n-1<<endl;
	}
	else {
		for(int i=0;i<n-2;i++) cout<<n-1<<" ";
		cout<<n<<" "<<n-1<<endl;
		
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









