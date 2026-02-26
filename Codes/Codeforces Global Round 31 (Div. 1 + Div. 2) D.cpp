// Problem: D. Insolvable Disks
// Contest: Codeforces - Codeforces Global Round 31 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2180/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> x(n);
	for(int i=0;i<n;i++) cin>>x[i];
	
	if (n == 1) {
		cout<<"0\n";
		return;
	}
	
	vector<int> a(n,inf);
	for(int i=1;i<n;i++) {
		int d=x[i]-x[i-1];
		a[i]=min(a[i],d);
		a[i-1]=min(a[i-1],d);
	}
		
	int l=0,r=a[0];
	int ans=n-1;
	for(int i=1;i<n;i++) {
		int d=x[i]-x[i-1];
		int l1=l,r1=r;
		l1=max(d-r,0ll);
		r1=min(d-l,a[i]);
		l=l1,r=r1;
		if (l >= r) {
			ans--;
			l=0;
			r=a[i];
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







