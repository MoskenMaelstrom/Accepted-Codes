// Problem: D. Absolute Cinema
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/D
// Memory Limit: 256 MB
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
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> b(n+1);
	for(int i=1;i<n;i++) b[i]=a[i]-a[i+1];
	vector<int> ans(n+1);
	for(int i=2;i<n;i++) ans[i]=b[i-1]-b[i]>>1;
	
	int sum1=0;
	for(int i=2;i<=n;i++) sum1+=ans[i]*(i-1);
	ans[n]=(a[1]-sum1)/(n-1);
	
	int sum2=0;
	for(int i=3;i<=n;i++) sum2+=ans[i]*(i-2);
	ans[1]=a[2]-sum2;
	
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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







