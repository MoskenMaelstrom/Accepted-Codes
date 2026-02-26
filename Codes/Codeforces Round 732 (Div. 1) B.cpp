// Problem: B. AquaMoon and Chess
// Contest: Codeforces - Codeforces Round 732 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1545/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int c0=0;
	int c1=0;
	for(int i=0;i<n;i++) {
		c0+=s[i] == '0';
	}
	for(int i=0;i<n-1;i++) {
		if (s[i] == '1' and s[i+1] == '1') {
			c1++;
			i++;
		}
	}
	cout<<C(c0+c1,c1)<<"\n";
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
	inv[N]=Pow(jc[N],p-2);
	for(int i=N-1;i>=0;i--) {
		inv[i]=(i+1)*inv[i+1]%p;
	}
	
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







