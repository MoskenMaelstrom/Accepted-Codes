// Problem: 宙天
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120563/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

int Sqrt(int n) {
    int x=sqrt(n);
    if (x*x > n) {
        x--;
    }
    return x;
}

void solve()
{
	int n;
	cin>>n;
	int x=Sqrt(n);
	if (x*(x+1) == n) cout<<"YES";
	else cout<<"NO";
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







