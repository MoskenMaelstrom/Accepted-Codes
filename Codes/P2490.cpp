// Problem: P2490 [SDOI2011] 黑白棋
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2490
// Memory Limit: 125 MB
// Time Limit: 1000 ms
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

const int p=1e9+7;
const int N=1e6;
int jc[N+1];

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

int C(int m,int n)
{
	if (m < n) return 0;
	return jc[m]*ny(jc[m-n])%p*ny(jc[n])%p;
}

void solve()
{
	int n,k,d;
	cin>>n>>k>>d;
	
	vector dp(17,vector<int>(n-k+1));//前i位,总和是j的数量 
	for(int j=0;j<=k/2;j+=d+1) dp[0][j]=C(k/2,j);
	
	for(int i=1;i<=16;i++) {
		for(int j=0;j<=n-k;j++) {
			for(int l=0;l<=k/2;l+=d+1) {
				if (j-(1ll<<i)*l < 0) continue;
				dp[i][j]+=dp[i-1][j-(1ll<<i)*l]*C(k/2,l)%p;
				dp[i][j]%=p;
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n-k;j++) {
		ans+=dp[16][j]*C(n-k/2-j,k/2)%p;
		ans%=p;
	}
	cout<<((C(n,k)-ans)%p+p)%p;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	jc[0]=1;
	for(int i=1;i<=N;i++) {
		jc[i]=jc[i-1]*i%p;
	}
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









