// Problem: I. Dating Day
// Contest: Codeforces - 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105911/problem/I
// Memory Limit: 16 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int p=998244353;
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
	string s;
	cin>>s;
	s=" "+s;
	
	int ans=0;
	int pl=0,pr=0,l=1,r=0;
	int c1=0;
	while (l <= n and r <= n) {
		while (r+1 <= n and c1 < k) {
			r++;
			c1+=s[r] == '1';
		}
		while (r+1 <= n and s[r+1] == '0') r++;
		if (c1 != k) {r++;continue;}
		(ans+=C(r-l+1,c1))%=p;
		if (pl != 0) (ans-=C(pr-l+1,c1-1))%=p;
		
		pl=l,pr=r;
		if (s[l] != '1') {
			while (l+1 <= n and s[l] == '0') l++;
		}
		l++;
		c1--;
	}
	cout<<(ans+p)%p<<"\n";
}

signed main()
{
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;

	//连续阶乘逆元的线性递推
	inv[N]=Pow(jc[N],p-2);
	for(int i=N-1;i>=0;i--) inv[i]=(i+1)*inv[i+1]%p;
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







