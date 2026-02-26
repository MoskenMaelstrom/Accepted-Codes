// Problem: A. Alice and Bob
// Contest: Codeforces - Educational Codeforces Round 184 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2169/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,a;
	cin>>n>>a;
	vector<int> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	int b1=a-1,b2=a+1;
	int c1=0,c2=0;
	for(int i=0;i<n;i++) {
		if (abs(a-vec[i]) > abs(b1-vec[i])) c1++;
		if (abs(a-vec[i]) > abs(b2-vec[i])) c2++;
	}
	
	if (c1 < c2) cout<<b2<<"\n";
	else cout<<b1<<"\n";
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







