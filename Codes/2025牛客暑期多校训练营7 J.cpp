// Problem: Ivory
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108304/J
// Memory Limit: 2048 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int p=998244353;

int pow(int base, int exp, int mod) {
    int res = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return res;
}
int ny(int num) {
	return pow(num,p-2,p)%p;
}

int f(int a,int b,int c,int d) {
	if (b == 0 or d == 0 or a == 1 or c == 1) return 1;
	int g=gcd(a,c);
	if (g == 1) return 1;
	
	if (d < b) {swap(a,c);swap(b,d);}
	return pow(g,b,p)*f(a/g,b,c,d-b)%p;
}

void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	cout<<f(a,b,c,d)<<"\n";
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









