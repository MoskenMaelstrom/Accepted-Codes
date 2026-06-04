// Problem: F. 交换余生
// Contest: Codeforces - The 2026 ICPC China Sichuan Provincial Programming Contest
// URL: https://codeforces.com/gym/106570/problem/F
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct Sieve {
    vector<int> spf,primes;

    Sieve(int n=1e6) : spf(n+1) {
        for (int i=2;i<=n;i++) {
            if (!spf[i]) primes.push_back(spf[i]=i);
            for (int p : primes) {
                if (i*p > n) break;
                spf[i*p]=p;
                if (i%p == 0) break;
            }
        }
    }

    // [质因子,指数] O(logn)
	vector<pair<int,int>> fact(int v) {
	    vector<pair<int,int>> res;
	    for (int p : primes) {
	        if (p*p > v or v < spf.size()) break;
	        if (v%p == 0) {
	            int c=0;
	            while (v%p == 0) v/=p,c++;
	            res.emplace_back(p,c);
	        }
	    }
	    while (v > 1 and v < spf.size()) {
	        int p=spf[v];
	        int c=0;
	        while (v%p == 0) v/=p,c++;
	        res.emplace_back(p,c);
	    }
	    if (v > 1) res.emplace_back(v,1);
	    return res;
	}

	//所有因数,O(O(fact)+因数个数)
    vector<int> divs(int v) {
        vector<int> res={1};
        for (auto [p,c] : fact(v)) {
            int sz=res.size();
            int x=p;
            for (int i=0;i<c;i++,x*=p)
                for (int j=0;j<sz;j++) res.push_back(res[j]*x);
        }
        return res;
    }

	//可筛1e12
    bool isPrime(int v) {
        if (v < spf.size()) return v > 1 and spf[v] == v;
        for (int p : primes) {
            if (p*p > v) break;
            if (v%p == 0) return 0;
        }
        return v > 1;
    }
};

Sieve sieve;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	int g=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		g=gcd(g,a[i]);
	}
	for(int i=0;i<n;i++) a[i]/=g;
	
	vector<int> vec;
	for(auto [p,c] : sieve.fact(a[0])) vec.push_back(p);
	for(auto [p,c] : sieve.fact(a[1])) vec.push_back(p);
	
	auto check=[&](int p) {
		vector<int> v;
		for(auto x : a) {
			if (x%p != 0) v.push_back(x);
		}
		int m=v.size();
		vector<int> pre(m+1),suf(m+1);
		for(int i=0;i<m;i++) pre[i+1]=gcd(pre[i],v[i]);
		for(int i=m-1;i>=0;i--) suf[i]=gcd(suf[i+1],v[i]);
		for(int i=0;i<m;i++) {
			if (gcd(pre[i],suf[i+1]) != 1) return 1;
		}
		return 0;
	};
	
	for(auto p : vec) {
		if (check(p)) {cout<<"YES\n";return;}
	}
	cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







