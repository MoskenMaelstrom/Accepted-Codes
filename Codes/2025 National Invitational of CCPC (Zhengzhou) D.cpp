// Problem: D. 2025
// Contest: Codeforces - 2025 National Invitational of CCPC (Zhengzhou), 2025 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105941/problem/D
// Memory Limit: 2048 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
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
	int y;
	cin>>y;
	int num=y;
	int ans=0;
	auto f=[&](int x) {
		if (Sqrt(x)*Sqrt(x) == x) return 1;
		else return 0;
	};
	
	int cnt=0;
	while (y) {
		cnt+=y%10;
		y/=10;
	}
	
	if (f(num) and f(cnt)) cout<<"Yes";
	else cout<<"No";
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







