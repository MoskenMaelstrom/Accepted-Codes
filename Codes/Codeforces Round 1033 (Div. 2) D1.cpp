// Problem: D. Matrix game
// Contest: Codeforces - Codeforces Round 1033 (Div. 2) and CodeNite 2025
// URL: https://codeforces.com/problemset/problem/2120/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int N=1e5+5;
const int p=1e9+7;
int jc[N];
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

int C(int lo,int hi) {
	int res=ny(jc[hi]);
	while (hi--) {
		res*=lo;
		lo--;
		res%=p;
	}
	return res;
}

void solve()
{
	int a,b,k;
	cin>>a>>b>>k;
	int n=k*(a-1)+1;
	n%=p;
	int m=k*C(n,a)%p*(b-1)+1;
	m%=p;
	
	cout<<n<<" "<<m<<"\n";
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
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









