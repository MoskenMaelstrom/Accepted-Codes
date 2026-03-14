// Problem: D. Do you play Ballance?
// Contest: Codeforces - The 6th Liaoning Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106380/problem/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int c1=0,c2=0,c3=0;
	int c4=0,c5=0,c6=0;
	for(int i=0;i<n;i++) {
		int n1,n2,n3;
		cin>>n1>>n2>>n3;
		if (n1) c1++;
		if (n2) c2++;
		if (n3) c3++;
		if (n1 or n2) c4++;
		if (n1 or n3) c5++;
		if (n2 or n3) c6++;
	}
	if (c1 == n or c2 == n or c3 == n) cout<<1<<"\n";
	else if (c4 == n or c5 == n or c6 == n) cout<<2<<"\n";
	else cout<<3<<"\n";
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







