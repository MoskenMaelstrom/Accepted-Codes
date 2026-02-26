// Problem: D. Unfair Game
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unbgned long long
using namespace std;

const int p=1e9+7;
const int N=1e5;
int jc[N+1];
int inv[N+1];

int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

int C(int m,int n)
{
	if (m < n) return 0;
	return jc[m]*inv[m-n]%p*inv[n]%p;
}

void solve()
{
	int n,k;
	cin>>n>>k;
    int t=1;
    int b=1;
    int ans=0;
    while (t < n) {
        for (int i=1;i<=b;i++) {
            if (i+b-1 <= k) ans+=C(b-1,i-1);
        }
        b++;
        t<<=1;
    }
    
    if (b <= k) ans++;
    cout<<n-ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;
	inv[N]=Pow(jc[N],p-2);
	for(int i=N-1;i>=0;i--) inv[i]=(i+1)*inv[i+1]%p;
	
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







