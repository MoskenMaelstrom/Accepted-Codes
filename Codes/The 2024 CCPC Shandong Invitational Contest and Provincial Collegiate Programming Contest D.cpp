// Problem: D. Hero of the Kingdom
// Contest: Codeforces - The 2024 CCPC Shandong Invitational Contest and Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105385/problem/D
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
	int p,a,b;
	cin>>p>>a>>b;
	int q,c,d;
	cin>>q>>c>>d;
	int m,t;
	cin>>m>>t;
	if (m/p == 0) {cout<<m<<"\n";return;}
	while (1) {
		int x=m/p;
		int dt=a*x+b+c*x+d;
		if (t-dt < 0) break;
		int k=min(t/dt,(p-m%p+x*(q-p)-1)/(x*(q-p)));
		t-=k*dt;
		m+=k*x*(q-p);
	}
	
	t-=b+d;
	if (t <= 0) {cout<<m<<"\n";return;}
	
	int x=min(m/p,t/(a+c));
	m+=x*(q-p);
	cout<<m<<"\n";
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







