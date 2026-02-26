// Problem: P3197 [HNOI2008] 越狱
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3197
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e5+3;

// 快速幂函数，计算 (baseexponent) % mod
int mod_exp(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;  // 防止base本身就大于mod

    while (exponent > 0) {
        // 如果 exponent 是奇数，将 base 乘入结果
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        // exponent 是偶数，将 base 平方并减半 exponent
        exponent = exponent >> 1;  // 等价于 exponent /= 2
        base = (base * base) % mod;
    }

    return result;
}

void solve()
{
	int m,n;
	cin>>m>>n;
	int ans=mod_exp(m,n,MOD)-(m%MOD*mod_exp(m-1,n-1,MOD))%MOD;
	cout<<(ans%MOD+MOD)%MOD;
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









