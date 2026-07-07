// Problem: C. Unstable Elements
// Contest: Codeforces - Educational Codeforces Round 192 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2242/problem/C
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> cnt(n+1);
	for(int i=0;i<n;i++) cnt[a[i]]++;
	
	vector<int> vec;
	for(int i=0;i<=n;i++) {
		if (cnt[i]) vec.push_back(cnt[i]);
	}
	
	int sum=n;
	int m=vec.size();
	int kind=vec.size();
	int ans=0;
	ranges::sort(vec);
	int lst=0;
	for(int i=0;i<m;) {
		int c=1;
		while (i < m-1 and vec[i] == vec[i+1]) c++,i++;
			
		for(int j=vec[i]-lst;j>=1;j--) {
			if (sum != 0 and sum <= k and (k-sum)%kind == 0) {
				ans++;
				sum-=kind*j;
				break;
			}
			sum-=kind;
		}
		lst=vec[i];
		kind-=c;
		i++;
	}
	cout<<ans<<"\n";
}
	
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







