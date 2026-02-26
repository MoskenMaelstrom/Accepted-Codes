// Problem: D. Even String
// Contest: Codeforces - Educational Codeforces Round 177 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2086/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int p=998244353;
int pow(int base, int exp, int mod) {
    int res = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return res;
}
int ny(int num) {
	return pow(num,p-2,p)%p;
}

const int n=26,N=5e5;
int jc[N+1];

int C(int m,int n)
{
	if (m < n) return 0;
	return jc[m]*ny(jc[m-n])%p*ny(jc[n])%p;
}

void solve()
{
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int m=accumulate(a.begin(),a.end(),0);
	int m1=m/2,m0=m-m1;
	
	int sum=0;
	for(int i=0;i<n;i++) {
		if (a[i] >= 2) sum+=a[i];
	}
	vector<int> dp(m0+1,0);
	dp[0]=1;
	for(int i=0;i<n;i++) {
		if (a[i] <= 1) continue;
		for(int j=m0;j>=a[i];j--) {
			dp[j]+=dp[j-a[i]];
		}
	}
	
	int div=1;
	for(int i=0;i<n;i++) {
		div*=jc[a[i]];
		div%=p;
	}
	
	int ans=0;
	for(int j=0;j<=m0;j++) {
		if (dp[j] == 0 or sum-j > m1) continue;
		ans+=dp[j]*C(m0,j)%p*jc[j]%p*C(m1,sum-j)%p*jc[sum-j]%p*jc[m-sum]%p*ny(div)%p;
		ans%=p;
	}
	cout<<ans<<"\n";
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
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









