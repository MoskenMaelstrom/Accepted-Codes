// Problem: G. Path Summing Problem
// Contest: Codeforces - 2025 ICPC Wuhan Invitational Contest (The 3rd Universal Cup. Stage 37: Wuhan)
// URL: https://codeforces.com/gym/105901/problem/G
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
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
	int n,m;
	cin>>n>>m;
	vector a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	
	int ans=0;
	vector dp(n*m+1,vector<array<int,3>>(0));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			int res=C(i+j-2,i-1);
			for(auto [x,y,v] : dp[a[i][j]]) {
				if (x > i or y > j) continue;
				(res-=v*C(i-x+j-y,i-x))%=p;
			}
			if (res == 0) continue;
			dp[a[i][j]].push_back({i,j,res});
			(ans+=res*C(n-i+m-j,n-i)%p)%=p;
		}
	}
	cout<<(ans+p)%p<<"\n";
}

signed main()
{
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;
	
	inv[N]=Pow(jc[N],p-2);
	for(int i=N-1;i>=0;i--) inv[i]=(i+1)*inv[i+1]%p;
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







