// Problem: Another Day of Sun
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108299/A
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<array<int,2>> dp(n);
	int cnt=0;
	if (a[0] != 0) dp[0][1]=1;
	if (a[0] == -1) cnt++;
	
	for(int i=1;i<n;i++) {
		if (a[i] == 1) {
			if (a[i-1] == 0) dp[i][1]=dp[i-1][0]+pow(2,cnt,p)+dp[i-1][1];
			if (a[i-1] == 1) dp[i][1]=dp[i-1][0]+dp[i-1][1];
			if (a[i-1] == -1) dp[i][1]=dp[i-1][0]+pow(2,cnt-1,p)+dp[i-1][1];
		}
		if (a[i] == 0) {
			dp[i][0]=dp[i-1][1]+dp[i-1][0];
		}
		if (a[i] == -1) {
			dp[i][0]=dp[i-1][1]+dp[i-1][0];
			if (a[i-1] == 0) dp[i][1]=dp[i-1][0]+pow(2,cnt,p)+dp[i-1][1];
			if (a[i-1] == 1) dp[i][1]=dp[i-1][0]+dp[i-1][1];
			if (a[i-1] == -1) dp[i][1]=dp[i-1][0]+pow(2,cnt-1,p)+dp[i-1][1];
			cnt++;
		}
		dp[i][0]%=p;
		dp[i][1]%=p;
	}
	
	cout<<(dp[n-1][0]+dp[n-1][1])%p<<'\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









