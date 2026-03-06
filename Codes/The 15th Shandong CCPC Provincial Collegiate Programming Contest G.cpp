// Problem: G. Assembly Line
// Contest: Codeforces - The 15th Shandong CCPC Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105930/problem/G
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		int w,t;
		cin>>w>>t;
		a[i]=k+t-w;
	}
	ranges::sort(a);
	for(int i=1;i<n;i++) a[i]=max(a[i],a[i-1]+1);
	cout<<a[n-1]<<"\n";
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







