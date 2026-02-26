// Problem: D. Segments Covering
// Contest: Codeforces - Educational Codeforces Round 181 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2125/D
// Memory Limit: 256 MB
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

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,3>> a(n+1);
	for(int i=1;i<=n;i++) {
		int l,r,fz,fm;
		cin>>l>>r>>fz>>fm;
		a[i][0]=l;
		a[i][1]=r;
		a[i][2]=fz*ny(fm)%p;
	}
	sort(a.begin()+1,a.end());
	
	vector<int> R(m+1,1);//idx=r的区间，全都不取的概率积
	for(int i=1;i<=n;i++) {
		auto [l,r,P]=a[i];
		R[r]*=(1-P+p)%p;
		R[r]%=p;
	}
	vector<int> preR(m+1,1);//idx<=r
	for(int i=1;i<=m;i++) {
		preR[i]=preR[i-1]*R[i]%p;
	}
	
	
	vector<int> dp(m+1);
	dp[0]=1;
	for(int i=1;i<=n;i++) {
		auto [l,r,P]=a[i];
		dp[r]+=dp[l-1]*P%p*(preR[r]*ny(preR[l-1])%p*ny(1-P+p)%p)%p;
		dp[r]%=p;
	}
	cout<<dp[m]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









