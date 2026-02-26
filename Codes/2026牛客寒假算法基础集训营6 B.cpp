// Problem: 小L的彩球
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=998244353;
const int N=1e6;
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
	int n,x,t;
	cin>>n>>x>>t;
	int k=t+1>>1;
	if (t == 0 and x == n) {cout<<1<<"\n";return;}
	else if (t == 0) {cout<<0<<"\n";return;}
	
	if (t&1) {
		cout<<2*C(x-1,k-1)%p*C(n-x-1,k-1)%p<<"\n";
	}
	else {
		cout<<(C(x-1,k)*C(n-x-1,k-1)%p+C(x-1,k-1)*C(n-x-1,k)%p)%p<<"\n";
	}
	
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







