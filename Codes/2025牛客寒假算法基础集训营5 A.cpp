#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int x;
	char o;
	cin>>x>>o;
	if (o == '+') cout<<x-1<<" 1\n";
	if (o == '-') cout<<x+1<<" 1\n";
	if (o == '*') cout<<x<<" 1\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









