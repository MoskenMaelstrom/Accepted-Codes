// Problem: G. Skibidus and Capping
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/problemset/problem/2065/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

struct Sieve {
    vector<bool> isp;  //判断i是不是质数
    vector<int> primes;  //存储所有<top的质数
    int top;
 
    Sieve(int top_ = 300300) {
        top = top_ + 1;
        isp.assign(top, true);
        isp[1] = false;
        for (int i = 2; i < top; ++i) {
            if (isp[i]) {
                primes.push_back(i);
            }
            // Euler sieve method O(n).
            for (int p : primes) {
                int x = i * p;
                if (x >= top)
                    break;
                isp[x] = false;
                if (i % p == 0)
                    break;
            }
        }
    }

	//O(v^(1/2))
    map<int, int> factorization(int v) {
        map<int, int> res;
        for (int p : primes) {
            if (v == 1)
                break;
            if (i64(p) * p > v)
                break;
            int cnt = 0;
            while (v % p == 0) {
                cnt++;
                v /= p;
            }
            if (cnt) {
                res[p] = cnt;
            }
        }
        if (v > 1)
            res[v] = 1; // final large prime.
        return res;
    }
 
 	//O(num^(1/2)+num的因数个数)
    vector<int> divisors(int v) {
        map<int, int> f = factorization(v);
        vector<int> res;
        res.push_back(1);
        for (auto [p, c] : f) {
            int t = res.size(), x = 1;
            for (int i = 0; i < c; ++i) {
                x *= p;
                for (int j = 0; j < t; ++j)
                    res.push_back(res[j] * x);
            }
        }
        return res;
    }

    bool isprime(int v) {
        if (v < top)
            return isp[v];
        assert(i64(top - 1) * (top - 1) >= v);
        for (int p : primes)
            if (v % p == 0)
                return false;
        return true;
    }
};

const int N=2e5+5;
Sieve sieve(N);
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	vector<int> tong(n+1);
	for(auto e1 : a) tong[e1]++;
	
	int ans=0;
	int cnt=0;
	for(auto e1 : a) {
		if (sieve.isp[e1]) cnt++;
	}
	for(int i=2;i<=n;i++) {
		if (sieve.isp[i]) ans+=tong[i]*(cnt-tong[i]);
	}
	ans/=2;
	
	for(int i=4;i<=n;i++) {
		auto fac=sieve.factorization(i);
		int cnt1=0;
		for(auto [e1,e2] : fac) cnt1+=e2;
		if (cnt1 == 2) {
			ans+=(tong[i]*(tong[i]+1))/2;
			for(auto [e1,e2] : fac) ans+=tong[i]*tong[e1];
		}
	}
	
	cout<<ans<<endl;
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









