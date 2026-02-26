// Problem: Love Wins All
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108299/L
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
int ny(int num) {
	return pow(num,p-2,p)%p;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {cin>>a[i];a[i]--;}
	
	int len=0;
	vector r(n,vector<int>(0));
	vector<bool> mark(n);
	for(int i=0;i<n;i++) {
		if (mark[i]) continue;
		mark[i]=1;
		r[len].push_back(i);
		int p=a[i];
		while (p != i) {
			mark[p]=1;
			r[len].push_back(p);
			p=a[p];
		}
		len++;
	}
	
	int cnt=0;
	for(int i=0;i<len;i++) {
		cnt+=r[i].size()%2;
	}
	
	int ans=0;
	if (cnt == 2) {
		ans=1;
		for(int i=0;i<len;i++) {
			int m=r[i].size();
			if (r[i].size()%2 == 1) {
				ans*=m;
			}
			else {
				ans*=m == 2 ? 1 : 2;
			}
			ans%=p;
		}
	}
	else if (cnt == 0) {
		int sum=1;
		for(int i=0;i<len;i++) {
			int m=r[i].size();
			sum*=m == 2 ? 1 : 2;
			sum%=p;
		}
		for(int i=0;i<len;i++) {
			int m=r[i].size();
			ans+=sum*ny(m == 2 ? 1 : 2)%p*(m*m%p*ny(4)%p);
			ans%=p;
		}
	}
	
	cout<<ans<<'\n';
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









