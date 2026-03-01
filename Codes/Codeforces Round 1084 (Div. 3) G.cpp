// Problem: G. Operation Permutation
// Contest: Codeforces - Codeforces Round 1084 (Div. 3)
// URL: https://codeforces.com/contest/2200/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int p=1e9+7;
const int N=1e4;
int jc[N+1];

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
	int n,x;
	cin>>n>>x;
	vector<int> mul;
	int add=0;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		int num=stoi(s.substr(1));
		num%=p;
		if (s[0] == '+') add+=num;
		else if (s[0] == '-') add-=num;
		else if (s[0] == 'x') mul.push_back(num);
		else mul.push_back(Inv(num));
		add%=p;
	}
	
	int m=mul.size();
	vector dp(m+1,vector<int>(m+1));
	for(int i=0;i<=m;i++) dp[i][0]=1;
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=i;j++) {
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*mul[i-1]%p;
			dp[i][j]%=p;
		}
	}
	
	int ans=x*dp[m][m]%p;
	for(int i=0;i<=m;i++) {
		ans+=jc[i]*jc[m-i]%p*Inv(jc[m+1])%p*dp[m][i]%p*add%p;
		ans%=p;
	}
	cout<<(ans+p)%p<<"\n";
}

signed main()
{
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







