// Problem: Buy One More
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133878/B
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
const int N=2e6+10;
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

int Inv(int num) {
	return Pow(num,p-2);
}

int C(int m,int n)
{
	if (m < n) return 0;
	return jc[m]*inv[m-n]%p*inv[n]%p;
}
	
void solve()
{
	int n,m,c,a,b;
	cin>>n>>m>>c>>a>>b;
	if (m < n or (m-n)%c) {cout<<"0\n";return;}
	int k=(m-n)/c;
	int res=a*Inv(b)%p;
	cout<<(n*Inv(m)%p*C(m,k)%p*Pow(res,k)%p*Pow(1-res,m-k)%p+p)%p<<"\n";
}

signed main()
{
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;
	inv[N]=Pow(jc[N],p-2);
	for(int i=N-1;i>=0;i--) inv[i]=(i+1)*inv[i+1]%p;
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







