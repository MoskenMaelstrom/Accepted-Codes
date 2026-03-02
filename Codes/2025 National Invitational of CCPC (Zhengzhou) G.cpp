// Problem: G. 直径与最大独立集
// Contest: Codeforces - 2025 National Invitational of CCPC (Zhengzhou), 2025 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105941/problem/G
// Memory Limit: 2048 MB
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
	if (n == 2) {cout<<"1 2\n";return;}
	if (n == 1 or n == 4) {cout<<"-1\n";return;}
	
	if (n&1) {
		for(int i=1;i<=n-2;i+=2) {
			cout<<i<<" "<<i+1<<"\n";
			cout<<i<<" "<<i+2<<"\n";
		}
	}
	else {
		for(int i=1;i<=n-3;i+=2) {
			cout<<i<<" "<<i+1<<"\n";
			cout<<i<<" "<<i+2<<"\n";
		}
		cout<<n<<" "<<2<<"\n";
	}
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







