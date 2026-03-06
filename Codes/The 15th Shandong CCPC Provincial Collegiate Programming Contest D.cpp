// Problem: D. Distributed System
// Contest: Codeforces - The 15th Shandong CCPC Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105930/problem/D
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	while (q--) {
		int m,b;
		cin>>m>>b;
		int t=m/n;
		int ed=(m+b)%n;
		if (b+m <= n) a[b]++,a[b+m]--;
		else if (ed < b) a[0]+=t+1,a[ed]--,a[b]++;
		else a[0]+=t,a[b]++,a[ed]--;
	}
	for(int i=1;i<n;i++) {
		a[i]=a[i-1]+a[i];
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
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









