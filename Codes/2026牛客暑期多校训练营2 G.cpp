// Problem: GCD Graph
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133877/G
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

    Sieve(int n=1e7) : spf(n+1) {
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

const int inf=1e9;
Sieve sieve;
void solve()
{
	int l,r,n;
	cin>>l>>r>>n;
	auto vec=sieve.fact(n);
	int m=vec.size();
	
	auto work1=[&](int L,int R) {
		int ans=0;
		for(int i=0;i<(1<<m);i++) {
			int cur=1;
			for(int j=0;j<m;j++) {
				if (((i>>j)&1)) cur*=vec[j].first;
			}
			int f;
			if (__builtin_popcount(i)&1) f=-1;
			else f=1;
			assert(cur > 0);
			ans+=f*(R/cur-(L-1)/cur);
		}
		return (R-L+1-ans)*2+ans;
	};
	
	int p=-1;
	for(int i=max(l,r-200);i<=n;i++) {
		if (sieve.isPrime(i) and i >= r) {
			cout<<work1(l,r)<<"\n";
			return;
		}
		else if (sieve.isPrime(i) and i < r) p=i;
	}
	
	auto work2=[&](int L,int R) {
		int len=n-L+1;
		vector<int> dp(len,inf);
		dp[n-L]=0;
		for(int i=n-1;i>=L;i--) {
			for(int j=i+1;j<=n;j++) {
				dp[i-L]=min(dp[i-L],gcd(i,j)+dp[j-L]);
			}
		}
		int sum=0;
		for(int i=L;i<=R;i++) sum+=dp[i-L];
		return sum;
	};
	
	if (p == -1) cout<<work2(l,r)<<"\n";
	else cout<<work1(l,p)+work2(p+1,r)<<"\n";
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







