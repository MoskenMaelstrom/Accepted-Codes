// Problem: K. 神之一手
// Contest: Codeforces - The 2025 Shanghai Collegiate Programming Contest
// URL: https://codeforces.com/gym/105992/problem/K
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=1e9+7;
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

int Inv(int num) {
	return Pow(num,p-2);
}

void solve()
{
	int P,Q,R;
	cin>>P>>Q>>R;
	(P*=inv[1000])%=p;
	(Q*=inv[1000])%=p;
	(R*=inv[1000])%=p;
	int p0=(1-P)%p;
	int p1=(1-P)*(1-Q)%p;
	
	int n;
	cin>>n;
	vector<array<int,2>> dp(n+1);
	dp[0]={1,0};
	int cnt=0;
	for(int i=1;i<=n;i++) {
		int a;
		cin>>a;
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1]*(1-R)%p;
		while (a > 0 and cnt < 80) {
			dp[i][1]=(dp[i][0]*(1-p0)%p+dp[i][1]*p0%p)%p;
			dp[i][0]=dp[i][0]*p0%p;
			cnt++;
			a--;
		}
		
		if (a > 0) {
			dp[i][1]=(dp[i][0]*a%p*(1-p1)%p*Pow(p1,a-1)%p+dp[i][1]*Pow(p1,a)%p)%p;
			dp[i][0]=dp[i][0]*Pow(p1,a)%p;
		}
		
		cout<<((dp[i-1][0]+dp[i-1][1]-dp[i][0]-dp[i][1])%p+p)%p<<"\n";
	}
}

signed main()
{
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;
	inv[1]=1;
	for(int i=2;i<=N;i++) inv[i]=p-inv[p%i]*(p/i)%p;
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







