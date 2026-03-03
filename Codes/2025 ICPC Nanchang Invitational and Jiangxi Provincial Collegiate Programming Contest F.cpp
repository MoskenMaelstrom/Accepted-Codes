// Problem: F. Caloric Difference
// Contest: Codeforces - 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105911/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const double eps=1e-8;
void solve()
{
	int n,k;
	cin>>n>>k;
	double r0,c0,p,L,R;
	cin>>r0>>c0>>p>>L>>R;
	vector<double> r(n);
	for(int i=0;i<k;i++) {
		int id;
		double ri;
		cin>>id>>ri;
		r[id-1]=ri;
	}
	
	for(int i=0;i<n;i++) {
		if (fabs(r[i]) < eps) r[i]=L;
	}
	
	double ans=0;
	for(int i=0;i<n;i++) {
		c0=p*c0+(1-p)*r0;
		r0=r[i];
		ans+=c0-r0;
	}
	cout<<fixed<<setprecision(10)<<ans<<"\n";
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







