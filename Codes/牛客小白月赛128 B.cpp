// Problem: 只留专一数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127265/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

vector<int> primes;
struct Sieve {
    vector<bool> isp;
    int top;
 
    Sieve(int top_ = 1000) {
        top = top_ + 1;
        isp.assign(top, true);
        isp[1] = false;
        for (int i = 2; i < top; ++i) {
            if (isp[i]) {
                primes.push_back(i);
            }
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
	//质因数:指数
    map<int, int> factorization(int v) {
        map<int, int> res;
        for (int p : primes) {
            if (v == 1)
                break;
            if (p * p > v)
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
            res[v] = 1;
        return res;
    }
 	
 	//返回v所有的因数
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

    bool isPrime(int v) {
        if (v < top)
            return isp[v];
        assert((top - 1) * (top - 1) >= v);
        for (int p : primes)
            if (v % p == 0)
                return false;
        return true;
    }
};

void solve()
{
	int n;
	cin>>n;
	bool ok=0;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		if (num == 1) ok=1;
		int cnt=0;
		for(auto e1 : primes) {
			if (num%e1 == 0) cnt++;
		}
		if (cnt == 1) ok=1;
	}
	if (ok) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	Sieve();
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







