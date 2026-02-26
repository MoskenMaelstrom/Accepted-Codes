// Problem: Ghost in the Parentheses
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108301/G
// Memory Limit: 2048 MB
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
	string s;
	cin>>s;
	int n=s.length();
	vector<int> a(n);
	a[0]=1;
	for(int i=1;i<n;i++) {
		if (s[i] == '(') a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	}
	
	vector<int> l(n);//左边的)的数量
	for(int i=1;i<n;i++) {
		l[i]=l[i-1];
		l[i]+=s[i] == ')' ? 1 : 0;
	}
	
	vector<int> r(n);//右边的(的数量
	for(int i=n-2;i>=0;i--) {
		r[i]=r[i+1];
		r[i]+=s[i] == '(' ? 1 : 0;
	}
	
	vector<int> ed(n);//右边a<=1的idx
	int pos=n-1;
	for(int i=n-1;i>=0;i--) {
		if (a[i] <= 1) pos=i;
		ed[i]=pos;
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		if (s[i] == '(') {
			ans+=ny(   pow(2,l[ed[i]],p)*pow(2,r[i],p)   %p)%p;
			ans%=p;
		}
	}

	ans+=ny(pow(2,n/2,p));
	ans%=p;
	
	cout<<ans<<'\n';
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









