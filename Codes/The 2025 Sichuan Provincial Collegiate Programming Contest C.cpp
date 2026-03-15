// Problem: C. Optimal Time
// Contest: Codeforces - The 2025 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105949/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;
struct Sieve {
    vector<int> spf,primes;

    Sieve(int n=1e5) : spf(n+1) {
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
	int n,q;
	cin>>n>>q;
	vector<double> dp(n+1);
	ranges::iota(dp,0);
	vector<vector<int>> div(n+1);
	for(int i=1;i<=n;i++) div[i]=sieve.divs(i);
	
	for(int _=0;_<100;_++) {
		for(int i=1;i<=n;i++) {
			double res=0;
			int cnt=0;
			auto &vec=div[i];
			for(auto x : vec) res+=dp[x-1],cnt++;
			for(int j=2*i;j<=n;j+=i) res+=dp[j-1],cnt++;
			dp[i]=min(dp[i-1]+1,res/cnt+1);
		}
	}
	
	while (q--) {
		int x;
		cin>>x;
		cout<<fixed<<setprecision(10)<<dp[x]<<"\n";
	}
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







