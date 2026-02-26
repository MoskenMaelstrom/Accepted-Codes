// Problem: 徽章计数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127265/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=1e9+7;
const int N=2e5;
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
	vector<int> cnt(n+1);
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		cnt[num]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++) {
		if (cnt[i]%i != 0) {
			cout<<"0\n";
			return;
		}
		sum+=cnt[i]/i;
	}
	if (sum > m) {
		cout<<"0\n";
		return;
	}
	
	int ans=1;
	for(int i=0;i<sum;i++) {
		ans*=(m-i)%p;
		ans%=p;
	}
	for(int i=1;i<=n;i++) {
		if (cnt[i] == 0) continue;
		ans*=jc[cnt[i]]%p;
		ans%=p;
		ans*=Pow(inv[i],cnt[i]/i);
		ans%=p;
		ans*=inv[cnt[i]/i];
		ans%=p;
	}
	cout<<ans<<"\n";
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







