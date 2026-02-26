// Problem: B1. Canteen (Easy Version)
// Contest: Codeforces - Codeforces Round 1012 (Div. 1)
// URL: https://codeforces.com/contest/2089/problem/B1
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1),b(n+1);
	vector<int> c(2*n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) c[i]=c[i+n]=a[i]-b[i];
	for(int i=1;i<=2*n;i++) c[i]=c[i-1]+c[i];
	
	int ans=0;
	for(int l=1,r=1;l<=n;l++){
		while(c[r]-c[l-1] > 0) r++;
		ans=max(ans,r-l+1),r+=(l==r);
	}
	cout<<ans<<endl;
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









