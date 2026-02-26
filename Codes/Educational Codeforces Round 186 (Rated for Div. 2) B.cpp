// Problem: B. New Year Cake
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int a,b;
	cin>>a>>b;
	int ans=0;
	int c0=0,c1=0;
	int i=0;
	while (c0 <= a and c1 <= b) {
		if (i%2 == 0) c0+=1<<i;
		else c1+=1<<i;
		i++;
	}
	if (c0 > a or c1 > b) i--;
	ans=i;
	
	i=0,c0=0,c1=0;
	while (c0 <= b and c1 <= a) {
		if (i%2 == 0) c0+=1<<i;
		else c1+=1<<i;
		i++;
	}
	
	if (c0 > b or c1 > a) i--;
	ans=max(ans,i);
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







