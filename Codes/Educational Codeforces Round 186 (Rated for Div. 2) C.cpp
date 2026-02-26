// Problem: C. Production of Snowmen
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	vector<int> c1(n);
	for(int i=0;i<n;i++) {
		int ok=1;
		for(int j=0;j<n;j++) {
			if (a[j] >= b[(i+j)%n]) ok=0;
		}
		c1[i]=ok*n;
	}
	
	a=b;
	for(int i=0;i<n;i++) cin>>b[i];
	int cnt=0;
	for(int i=0;i<n;i++) {
		int ok=1;
		for(int j=0;j<n;j++) {
			if (a[j] >= b[(i+j)%n]) ok=0;
		}
		cnt+=ok;
	}
	
	int ans=0;
	for(int i=0;i<n;i++) ans+=c1[i]*cnt;
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







