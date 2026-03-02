// Problem: L. Subsequence
// Contest: Codeforces - 2025 ICPC Wuhan Invitational Contest (The 3rd Universal Cup. Stage 37: Wuhan)
// URL: https://codeforces.com/gym/105901/problem/L
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	map<int,int> mp;
	for(int i=0;i<n;i++) mp[a[i]]++;
	
	int ans=1;
	for(int r=1;r<n;r++) {
		for(int l=0;l<r;l++) {
			int m=a[l]+a[r]>>1;
			int p=ranges::lower_bound(a,m)-a.begin();
			if ((a[l]+a[r])%2 or a[p] != m) continue;
			int d1=p-l-1;
			int d2=mp[m];
			int d3=r-p-d2;
			if (d1+d2 <= d3) ans=max(ans,(d1+d2<<1)+2);
			else if (d3+d2 <= d1) ans=max(ans,(d3+d2<<1)+1);
			else ans=max(ans,d1+d2+d3+2);
			// cout<<d1<<" "<<d2<<" "<<d3<<"\n";
		}
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







