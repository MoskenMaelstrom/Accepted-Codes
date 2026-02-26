// Problem: E. She knows...
// Contest: Codeforces - Codeforces Round 1014 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2092/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
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
	int n,m,k;
	cin>>n>>m>>k;
	
	vector<int> cnt(2);
	for(int i=0;i<k;i++) {
		int x,y,c;
		cin>>x>>y>>c;
		if ((x == 1)^(y == 1)^(x == n)^(y == m)) {
			cnt[c]++;
		}
	}

	int ans=pow(2,n*m-k,p)*ny(2)%p;
	if (cnt[0]+cnt[1] == 2*(n+m-4)) {
		if (cnt[1]%2 == 1) ans=0;
		else ans*=2;
	}
	
	cout<<ans%p<<endl;
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









