// Problem: B. Countless Me
// Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
// URL: https://codeforces.com/gym/105143/problem/B
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
	int n;
	cin>>n;
	vector<int> a(n);
	int sum=0;
	for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
	int ans=0;
	for(int i=30;i>=0;i--) {
		if (((1<<i)-1)*n < sum) {
			for(int j=0;j<n;j++) {
				if ((1<<i) <= sum) sum-=1<<i;
			}
			ans+=1<<i;
		}
	}
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







