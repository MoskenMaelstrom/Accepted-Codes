// Problem: D. 金麦园
// Contest: Codeforces - The 9th Hebei Collegiate Programming Contest
// URL: https://codeforces.com/gym/105909/problem/D 
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	ranges::sort(a);
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	
	auto work=[&](int x) -> int {
		int l=1,cnt=0;
		for(int r=2;r<=n;r++) {
			while (l <= r and a[r]-a[l] > x) l++;
			cnt+=r-l;
		}
		return cnt;
	};
	
	int lo=0,hi=a.back()-a[1],res=-1;
	while (lo <= hi) {
		int mid=hi+lo>>1;
		if (work(mid) >= k) res=mid,hi=mid-1;
		else lo=mid+1;
	}
	assert(res != -1);
	
	// cout<<res;
	int l=1,sum=0;
	for(int r=2;r<=n;r++) {
		while (l <= r and a[r]-a[l] > res-1) l++;
		sum+=(r-l)*a[r]-(pre[r-1]-pre[l-1]);
	}
	cout<<(k-work(res-1))*res+sum;
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







