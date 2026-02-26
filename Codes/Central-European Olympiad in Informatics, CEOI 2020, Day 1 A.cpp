// Problem: A. Fancy Fence
// Contest: Codeforces - Central-European Olympiad in Informatics, CEOI 2020, Day 1 (IOI, Unofficial Mirror Contest, Unrated)
// URL: https://codeforces.com/problemset/problem/1402/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=1e9+7;
void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0];
	for(int i=0;i<n;i++) cin>>a[i][1];
	
	vector<array<int,2>> sta;
	int ans=0;
	int sum=0;
	for(int i=0;i<n;i++) {
		auto [h,w]=a[i];
		int rest=0;
		while (!sta.empty() and sta.back()[0] >= h) {
			auto [h0,w0]=sta.back();
			sta.pop_back();
			sum-=w0*(h0*(h0+1)/2%p),sum%=p;
			rest+=w0,rest%=p;
		}
		sum+=rest*(h*(h+1)/2%p),sum%=p;
		ans+=sum*w,ans%=p;
		ans+=w*(w+1)/2%p*(h*(h+1)/2%p),ans%=p;
		sta.push_back({h,(w+rest)%p});
		sum+=w*(h*(h+1)/2%p),sum%=p;
	}
	cout<<(ans+p)%p;
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







