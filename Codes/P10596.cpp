// Problem: P10596 BZOJ2839 集合计数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10596
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

const int p=1e9+7;
const int N=1e6;
int jc[N+1];
int inv[N+1];
int Pow(int base,int exp,int mod) {
	int res=1;
	base%=mod;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=mod;
		base*=base,base%=mod;
	}
	return res;
}

int C(int m,int n)
{
	if (m < n) return 0;
	return jc[m]*inv[m-n]%p*inv[n]%p;
}

int g(int n,int i) {
	return C(n,i)*(Pow(2,Pow(2,n-i,p-1),p)-1+p)%p;
}

int f(int n,int k) {
	int res=0;
	for(int i=k;i<=n;i++) {
		if ((i-k)%2 == 0) res+=C(i,k)*g(n,i)%p;
		else res-=C(i,k)*g(n,i)%p;
		res%=p;
	}
	return res;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	cout<<(f(n,k)%p+p)%p;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	jc[0]=1;
	for(int i=1;i<=N;i++) {
		jc[i]=jc[i-1]*i;
		jc[i]%=p;
	}
	inv[N]=Pow(jc[N],p-2,p);
	for(int i=N-1;i>=0;i--) {
		inv[i]=(i+1)*inv[i+1]%p;
	}
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







