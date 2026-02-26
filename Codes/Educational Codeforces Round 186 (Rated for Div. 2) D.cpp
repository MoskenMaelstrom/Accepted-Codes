// Problem: D. Christmas Tree Decoration
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/D
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
const int N=50;
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
	vector<int> a(n);
	int sum=0;
	cin>>sum;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) sum+=a[i];
	
	int m=sum/n;
	int n1=sum%n;
	int n2=n-n1;
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (a[i] > m+1) {cout<<0<<"\n";return;}
	}
	for(int i=0;i<n;i++) cnt+=a[i]>=m+1;
	cout<<C(n1,cnt)*jc[cnt]%p*jc[n-cnt]%p<<"\n";
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







