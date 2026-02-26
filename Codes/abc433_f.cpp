// Problem: F - 1122 Subsequence 2
// Contest: AtCoder - AtCoder Beginner Contest 433
// URL: https://atcoder.jp/contests/abc433/tasks/abc433_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6;
int jc[N];
const int p=998244353;
int Pow(int base,int exp) {	
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

int ny(int num) {
	return Pow(num,p-2);
}

int C(int m,int n)
{
	if (m < n) return 0;
	return jc[m]*ny(jc[m-n])%p*ny(jc[n])%p;
}

int Lucas(int m,int n)
{
	if (m == 0) return 1;
	return C(m%p,n%p)*Lucas(m/p,n/p)%p;
}

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	
	int ans=0;
	for(int d=0;d<=8;d++) {
		char x=d+'0';
		char y=x+1;
		
		int cnty=0;
		for(auto c : s) {
			if (c == y) cnty++;
		}
		
		int cntx=0;
		for(auto c : s) {
			if (c == x) {
				cntx++;
				ans+=C(cntx+cnty-1,cntx);
				ans%=p;
			}
			else if (c == y) {
				cnty--;
			}
		}
	}
	cout<<ans;
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







