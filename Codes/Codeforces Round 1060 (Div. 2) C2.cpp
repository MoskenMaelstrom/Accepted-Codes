// Problem: C2. No Cost Too Great (Hard Version)
// Contest: Codeforces - Codeforces Round 1060 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2154/C2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
struct Sieve {
    vector<int> spf,primes;

    Sieve(int n=3e5) : spf(n+1) {
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
	vector<array<int,2>> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i][0];
	for(int i=0;i<n;i++) cin>>vec[i][1];
	ranges::sort(vec,[&](const array<int,2>& A,const array<int,2>& B) {
		return A[1] < B[1];
	});
	int ans=0;
	if (vec[0][0]&1) ans+=vec[0][1];
	if (vec[1][0]&1) ans+=vec[1][1];
	
	map<int,int> mp;
	for(int i=0;i<n;i++) {
		auto v=sieve.fact(vec[i][0]);
		for(auto [x,exp] : v) {
			mp[x]++;
		}
	}
	
	for(auto [x,cnt] : mp) {
		if (cnt >= 2) {cout<<0<<"\n";return;}
	} 
	
	for(int i=0;i<n;i++) {
		auto [a,b]=vec[i];
		auto v=sieve.fact(a);
		for(auto [x,exp] : v) mp[x]--;
		
		a++;
		auto v1=sieve.fact(a);
		for(auto [x,exp] : v1) {
			if (mp[x]) ans=min(ans,b);
		}
		
		for(auto [x,exp] : v) mp[x]++;
	}
	
	auto [a,b]=vec[0];
	auto v=sieve.fact(a);
	for(auto [x,exp] : v) mp[x]--;
	for(auto [x,cnt] : mp) {
		if (cnt == 0) continue;
		ans=min(ans,(a/x*x+x-a)*b);
	}
	
	cout<<ans<<"\n";
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







