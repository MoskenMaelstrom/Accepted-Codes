// Problem: D. Spell Generation
// Contest: Codeforces - The 2025 Jiangsu Collegiate Programming Contest, The 2025 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105945/problem/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
	int ans=n%10;
	for(int i=1;i<=18;i++) {
		n/=10;
		ans+=n%10*(1<<i);
	}
	cout<<ans<<"\n";
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







