// Problem: E - Many LCMs
// Contest: AtCoder - AtCoder Beginner Contest 445
// URL: https://atcoder.jp/contests/abc445/tasks/abc445_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int P=998244353;
const int N=1e6;
int jc[N+1];
int inv[N+1];

int Pow(int base,int exp) {
	int res=1;
	base%=P;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=P;
		base*=base,base%=P;
	}
	return res;
}

int Inv(int num) {
	return Pow(num,P-2);
}

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
	for(int i=0;i<n;i++) cin>>a[i];
	map<int,int> mp1;
	map<int,int> mp2;
	
	for(int i=0;i<n;i++) {
		auto vec=sieve.fact(a[i]);
		for(auto [fac,exp] : vec) {
			if (mp1.count(fac) == 0) mp1[fac]=exp;
			else if (mp1[fac] <= exp) mp2[fac]=mp1[fac],mp1[fac]=exp;
			else if (mp2[fac] <= exp) mp2[fac]=exp;
		}
	}
	
	int res=1;
	for(auto [fac,exp] : mp1) res*=Pow(fac,exp),res%=P;
	for(int i=0;i<n;i++) {
		int ans=res;
		auto vec=sieve.fact(a[i]);
		for(auto [fac,exp] : vec) {
			if (mp1[fac] == exp) {
				ans*=Inv(Pow(fac,exp));
				ans%=P;
				ans*=Pow(fac,mp2[fac]);
				ans%=P;
			}
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%P;
	
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







