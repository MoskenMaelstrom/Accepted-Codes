// Problem: F. Omega Numbers
// Contest: Codeforces - Codeforces Round 1070 (Div. 2)
// URL: https://codeforces.com/contest/2176/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

const int p=998244353;
const int N=2e5+5;
int o[N],c[N][7],e[N];
vector<int> d[N];

int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

void init() {
	for(int i=2;i<N;i++)
		if(!o[i]) for(int j=i;j<N;j+=i) o[j]++;
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j+=i) d[j].push_back(i);
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	int m=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		m=max(m,a[i]);
	}
	
	for(int i=0;i<=m;i++) {
		for(int j=0;j<7;j++) c[i][j]=0;
	}
		
	for(int x:a) {		
		int w=o[x];
		for(int v:d[x]) c[v][w]++;
	}
	
	int r=0;
	for(int i=0;i<7;i++) {
		for(int j=0;j<7;j++) {
			for(int g=m;g;g--) {
				int v=c[g][i]*c[g][j]%p;
				for(int l=2*g;l<=m;l+=g) v=(v-e[l]+p)%p;
				e[g]=v;
				if (v) {
					int b=i+j-o[g];
					if (b < 0) b=0;
					r=(r+v*Pow(b,k))%p;
				}
			}
			for(int g=1;g<=m;g++) e[g]=0;
		}
	}
	
	int s=0;
	for(int x:a) s=(s+Pow(o[x],k))%p;
	cout<<(r-s+p)%p*Pow(2,p-2)%p<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	init();
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}