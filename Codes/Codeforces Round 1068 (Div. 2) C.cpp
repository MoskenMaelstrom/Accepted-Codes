// Problem: C. Kanade's Perfect Multiples
// Contest: Codeforces - Codeforces Round 1068 (Div. 2)
// URL: https://codeforces.com/contest/2173/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	a.erase(unique(a.begin(),a.end()),a.end());
	int m=a.size();
	vector<int> vec(m);
	for(int i=0;i<n;i++) {
		for(int j=a[i]*2;j<=k;j+=a[i]) {
			auto it=ranges::lower_bound(a,j);
			if (it != a.end() and *it == j) vec[it-a.begin()]=1;
			else {cout<<"-1\n";return;}
		}
	}
	
	vector<int> b;
	for(int i=0;i<m;i++) {
		if (vec[i] == 0) b.push_back(a[i]);
	}
	cout<<b.size()<<"\n";
	for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
	cout<<"\n";
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







