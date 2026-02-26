// Problem: C. Devyatkino
// Contest: Codeforces - Codeforces Round 1004 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2067/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
#define int long long
using namespace std;

//不带mod
int pow(int base, int exp) {
    int res = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base);
        }

        exp = exp >> 1;
        base = (base * base);
    }

    return res;
}

bool check(int x)
{
	while (x != 0) {
		if (x%10 == 7) return 1;
		x/=10;
	}
	return 0;
}

void solve()
{
	int n,ans=999999999999;
	cin>>n;
	int num=n;
	if (check(n)) {cout<<0<<endl;return;}
	int wei=1;
	while (num >= 10) {
		num/=10;
		wei++;
	}
	for(int k=1;k<=wei;k++) {
		bool flag=0;
		num=n;
		int add=pow(10,k)-1;
		int opt=0;
		for(int i=0;i<30;i++) {
			opt++;
			num+=add;
			if (check(num)) {flag=1;break;}
		}
		if (flag) ans=min(ans,opt);
	}
	
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









