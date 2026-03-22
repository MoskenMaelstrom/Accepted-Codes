// Problem: G. student
// Contest: Codeforces - The 13th Shaanxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105891/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int maxn=*ranges::max_element(a);
	int minn=*ranges::min_element(a);
	int ans;
	if (n <= 2) ans=n;
	else if (a[0] == maxn and a[n-1] == minn or a[0] == minn and a[n-1] == maxn) ans=2;
	else if (a[0] ==  minn or a[0] == maxn or a[n-1] == minn or a[n-1] == maxn) ans=3;
	else ans=4;
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







