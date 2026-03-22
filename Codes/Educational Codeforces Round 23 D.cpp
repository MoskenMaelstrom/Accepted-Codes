// Problem: D. Imbalanced Array
// Contest: Codeforces - Educational Codeforces Round 23
// URL: https://codeforces.com/problemset/problem/817/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> L(n+1),R(n+1);
	vector<array<int,2>> sta;
	sta.push_back({inf,0});
	for(int i=1;i<=n;i++) {
		while (sta.back()[0] < a[i]) sta.pop_back();
		L[i]=sta.back()[1];
		sta.push_back({a[i],i});
	}
	
	sta.clear();
	sta.push_back({inf,n+1});
	for(int i=n;i>=1;i--) {
		while (sta.back()[0] <= a[i]) sta.pop_back();
		R[i]=sta.back()[1];
		sta.push_back({a[i],i});
	}
	
	int ans=0;
	for(int i=1;i<=n;i++) ans+=a[i]*(R[i]-i)*(i-L[i]);
	
	sta.clear();
	sta.push_back({-inf,0});
	for(int i=1;i<=n;i++) {
		while (sta.back()[0] > a[i]) sta.pop_back();
		L[i]=sta.back()[1];
		sta.push_back({a[i],i});
	}
	
	sta.clear();
	sta.push_back({-inf,n+1});
	for(int i=n;i>=1;i--) {
		while (sta.back()[0] >= a[i]) sta.pop_back();
		R[i]=sta.back()[1];
		sta.push_back({a[i],i});
	}
	for(int i=1;i<=n;i++) ans-=a[i]*(R[i]-i)*(i-L[i]);
	
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







