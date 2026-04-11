#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
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
	int n;
	cin>>n;
	vector<int> d1(n+2,0);
	vector<int> d2(n+2,0);
	vector<int> d3(n+2,0);
	for(int i=0;i<n;i++) {
		int l,r;
		cin>>l>>r;
		d1[l]++;
		d1[r+1]--;

		d2[n-r]++;
		d2[n-l+1]--;

		int L=max(l,n-r);
		int R=min(r,n-l);
		if (L <= R) {
			d3[L]++;
			d3[R+1]--;
		}
	}
	int ans=0;
	int pre1=0,pre2=0,pre3=0;
	for(int i=1;i<n;i++) {
		pre1+=d1[i];
		pre2+=d2[i];
		pre3+=d3[i];
		if (pre1+pre2-pre3 == n and i-(n-pre2) >= 0 and i-(n-pre2) <= pre3) {
			(ans+=C(pre3,i-(n-pre2)))%=p;
		}
	}
	cout<<ans;
}

signed main()
{
	
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;
	inv[N]=Pow(jc[N],p-2);
	for(int i=N-1;i>=0;i--) inv[i]=(i+1)*inv[i+1]%p;
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







