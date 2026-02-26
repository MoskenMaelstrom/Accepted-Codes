// Problem: Nice Doppelgnger
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108304/G
// Memory Limit: 2048 MB
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

struct Sieve {
    vector<bool> isp;  //判断i是不是质数
    vector<int> primes;  //存储所有<top的质数
    vector<int> cnt;  //存储所有<top的质数
    int top;
 
    Sieve(int top_ = 1000000) {
        top = top_ + 1;
        isp.assign(top, true);
        cnt.assign(top, 0);
        isp[1] = false;
        for (int i = 2; i < top; ++i) {
            if (isp[i]) {
            	cnt[i]=1;
                primes.push_back(i);
            }
            for (int p : primes) {
                int x = i * p;
                if (x >= top)
                    break;
                isp[x] = false;
            	cnt[x]=cnt[i]+1;
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

    bool isPrime(int v) {
        if (v < top)
            return isp[v];
        assert(i64(top - 1) * (top - 1) >= v);
        for (int p : primes)
            if (v % p == 0)
                return false;
        return true;
    }
};

Sieve sieve;
void solve()
{
	int n;
	cin>>n;
	vector<int> ans;
	for(int i=2;i<=n;i++) {
		if (sieve.cnt[i]%2 == 1) {
			ans.push_back(i);
		}
		if (ans.size() == n/2) break;
	}
	for(auto e1 : ans) cout<<e1<<' ';
	cout<<'\n';
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









