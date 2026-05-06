// Problem: B. Zhily and Mex and Max
// Contest: Codeforces - Codeforces Round 1097 (Div. 2,  Based on Zhili Cup 2026)
// URL: https://codeforces.com/contest/2224/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	int maxm=0;
	int maxn=a.back();
	for(int i=0;i<n;i++) {
		if (maxm == a[i]) maxm++;
	}
	
	if (maxm != maxn+1) cout<<maxn*n+(1+maxm)*maxm/2+(n-1-maxm)*maxm<<"\n";
	else cout<<maxn*n+(1+maxm-1)*(maxm-1)/2+(n-maxm)*maxm+1<<"\n";
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







