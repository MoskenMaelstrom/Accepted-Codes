// Problem: Beautiful Matrix
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108303/D
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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

const int N=5e5+5;
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

int jc[N];
void solve()
{
	int n,m;
	cin>>n>>m;
	
	int ans=1;
	for(int i=m+n*(n-1);i>n*(n-1);i--) {
		ans*=i%p;
		ans%=p;
	}
	cout<<ans*ny(jc[m])%p;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	jc[0]=1;
	for(int i=1;i<N;i++) {
		jc[i]=jc[i-1]*i;
		jc[i]%=p;
	}
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









