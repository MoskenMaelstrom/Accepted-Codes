// Problem: K. Matrix
// Contest: Codeforces - The 2024 CCPC Shandong Invitational Contest and Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105385/problem/K
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	cout<<"Yes\n";
	for(int i=1;i<=n;i++) cout<<i<<" ";
	cout<<"\n";
	for(int i=2;i<=n-1;i++) {
		for(int j=1;j<=n;j++) cout<<i+n-1<<" ";
		cout<<"\n";
	}
	for(int i=1;i<=n-2;i++) cout<<i<<" ";
	cout<<2*n-1<<" "<<2*n;
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







