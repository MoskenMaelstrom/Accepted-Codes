// Problem: B. Deletion Sort
// Contest: Codeforces - Codeforces Round 1084 (Div. 3)
// URL: https://codeforces.com/contest/2200/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	auto b=a;
	ranges::sort(b);
	if (a == b) cout<<n<<"\n";
	else cout<<1<<"\n";
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







