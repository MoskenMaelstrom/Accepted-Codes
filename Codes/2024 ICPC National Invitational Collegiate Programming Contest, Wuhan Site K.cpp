// Problem: K. Party Games
// Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
// URL: https://codeforces.com/gym/105143/problem/K
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int a[1000001];
void solve()
{
	int n;
	cin>>n;
	if (a[n] == 1 or a[n] == n) cout<<"Fluttershy\n";
	else cout<<"Pinkie Pie\n";
}	

signed main()
{
	for(int i=1;i<=1000000;i++) a[i]=a[i-1]^i;
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







