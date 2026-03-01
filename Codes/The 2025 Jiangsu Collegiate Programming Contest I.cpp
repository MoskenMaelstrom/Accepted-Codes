// Problem: I. Team Naming
// Contest: Codeforces - The 2025 Jiangsu Collegiate Programming Contest, The 2025 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105945/problem/I
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
	vector<int> x(n),y(n),z(n);
	for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>z[i];
	
	map<int,int> a,b,c;
	map<array<int,2>,int> d,e,f;
	for(int i=0;i<n;i++) {
		a[x[i]]++;
		b[y[i]]++;
		c[z[i]]++;
		d[{x[i],y[i]}]++;
		e[{x[i],z[i]}]++;
		f[{y[i],z[i]}]++;
	}
	
	int A,B,C,D,E,F;
	int ans=0;
	for(int i=0;i<n;i++) {
		D=d[{x[i],y[i]}]-1;
		E=e[{x[i],z[i]}]-1;
		F=f[{y[i],z[i]}]-1;
		A=a[x[i]]-1-D-E;
		B=b[y[i]]-1-D-F;
		C=c[z[i]]-1-E-F;
		ans+=A*B+A*C+A*D+A*E+A*F+B*C+B*D+B*E+B*F+C*D+C*E+C*F+D*E+D*F+E*F;
		ans+=D*(D-1)/2+E*(E-1)/2+F*(F-1)/2;
	}
	cout<<ans;
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







