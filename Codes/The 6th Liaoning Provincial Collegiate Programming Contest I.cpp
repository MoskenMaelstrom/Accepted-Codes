// Problem: I. I take from the richer
// Contest: Codeforces - The 6th Liaoning Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106380/problem/I
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,cnt;
	cin>>n>>cnt;
	n--;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	for(int i=0;i<n;i++) {
		if (cnt < a[i]) cnt=cnt+a[i]+1>>1;
	}
	cout<<cnt<<"\n";
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







