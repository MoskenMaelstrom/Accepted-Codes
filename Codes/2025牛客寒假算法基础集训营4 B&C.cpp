#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long MOD=1e9+7;

int mod_exp(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;  // 防止base本身就大于mod

    while (exponent > 0) {
        // 如果 exponent 是奇数，将 base 乘入结果
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        // exponent 是偶数，将 base 平方并减半 exponent
        exponent = exponent >> 1;  // 等价于 exponent /= 2
        base = (base * base) % mod;
    }

    return result;
}

void solve()
{
	int n;
	string s;
	cin>>n>>s;
	if (n==1) {
		if (s[0] == '?') cout<<2<<endl;
		else cout<<1<<endl;
		return;
	}
	
	int cnt1=0,cnt2=0,cnt3=0;
	if (s[0] == '?') cnt1++;
	if (s[n-1] == '?') cnt2++;
	for(int i=1;i<n-1;i++) if (s[i] == '?') cnt3++;
	
	if (cnt1 == 0 and cnt2 == 0) {
		if (s[0] == s[n-1]) cout<<(n-2)*mod_exp(2,cnt3,MOD)%MOD<<endl;
		else cout<<2*mod_exp(2,cnt3,MOD)%MOD<<endl;
	}
	else if (cnt1+cnt2 == 1) {
		cout<<(  (n-2)*mod_exp(2,cnt3,MOD)%MOD+2*mod_exp(2,cnt3,MOD)  )%MOD<<endl;
	}
	else {
		cout<<(  2*(n-2)*mod_exp(2,cnt3,MOD)%MOD+4*mod_exp(2,cnt3,MOD)  )%MOD<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









