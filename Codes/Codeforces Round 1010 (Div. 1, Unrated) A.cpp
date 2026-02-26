// Problem: A. Math Division
// Contest: Codeforces - Codeforces Round 1010 (Div. 1, Unrated)
// URL: https://codeforces.com/problemset/problem/2081/A
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

const int p=1e9+7;
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	if (n == 1) {cout<<"0\n";return;}
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		a[i]=s[i]-'0';
	}
	
	ranges::reverse(a);
	vector<int> dp(n);
	dp[0]=a[0] == 1 ? ny(2) : 0;	
	for(int i=1;i<n;i++) {
		if (a[i] == 0) dp[i]=dp[i-1]*ny(2);
		else dp[i]=dp[i-1]+(1-dp[i-1])*ny(2);
		dp[i]%=p;
	}
	cout<<(((n-1)*(1-dp[n-2])+n*dp[n-2])%p+p)%p<<"\n";
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









