// Problem: B. Festival Decorating
// Contest: Codeforces - The 2023 ICPC Asia Hangzhou Regional Contest (The 2nd Universal Cup. Stage 22: Hangzhou)
// URL: https://codeforces.com/gym/104976/problem/B
// Memory Limit: 1024 MB
// Time Limit: 9000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=2.5e5+5;
bitset<N> f,b[19];
void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1),c(n+1);
	vector vec(n+1,vector<int>(0));
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		f[a[i]]=1;
		vec[c[i]].push_back(i);
	}
	
	vector<int> id(n+1);
	for(int j=1;j<=n;j++) id[j]=__lg(j);
	
	for(int i=1;i<=n;i++) {
		for(auto j : vec[i]) f[a[j]]=0;
		for(auto j : vec[i]) b[id[j]]|=(f>>a[j]);
		for(auto j : vec[i]) f[a[j]]=1;
	}
	
	while (q--) {
		int d;
		cin>>d;
		int ans=0;
		while ((1<<ans) <= n) {
			if (b[ans][d]) break;
			ans++;
		}
		if ((1<<ans) > n) cout<<"0\n";
		else cout<<(1<<ans)<<"\n";
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







