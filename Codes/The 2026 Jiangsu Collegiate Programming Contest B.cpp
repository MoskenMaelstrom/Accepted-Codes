// Problem: B. Galaxy of Stars in a Dream
// Contest: Codeforces - The 2026 Jiangsu Collegiate Programming Contest, The 2026 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106550/problem/B
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int x;
	cin>>x;
	int sx=sqrt(x);
	int mini=inf;
	int i=0;
	while (1) {
		while (sx*(sx+i) > x) sx--;
		int c=x-sx*(sx+i);
		mini=min(mini,max(abs(c-sx),abs(c-sx-i)));
		if (c >= sx and c <= sx+i or mini == i) {
			cout<<i<<"\n";
			return;
		}
		i++;
	}
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







