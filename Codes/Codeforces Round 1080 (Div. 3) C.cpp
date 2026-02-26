// Problem: C. Dice Roll Sequence
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/C
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<n;i++) {
		if (a[i] == 7-a[i-1] or a[i] == a[i-1]) ans++,i++;
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







