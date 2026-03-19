// Problem: F. Custom-Made Clothes
// Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
// URL: https://codeforces.com/gym/105143/problem/F
// Memory Limit: 1024 MB
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
	int n,k;
	cin>>n>>k;
	auto query=[&](int i,int j,int x) -> int {
		if (x == 0) return 0;
		cout<<"? "<<i<<" "<<j<<" "<<x<<endl;
		int ans;
		cin>>ans;
		return ans;
	};
	
	auto check=[&](int x) -> bool {
		int ans=0;
		for(int i=n,j=1;i>=1;i--) {
			while (j <= n and query(i,j,x-1)) j++;
			ans+=n-j+1;
		}
		return ans >= k;
	};
	
	int lo=1,hi=n*n,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,lo=mid+1;
		else hi=mid-1;
	}
	assert(res != -1);
	cout<<"! "<<res<<endl;
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







