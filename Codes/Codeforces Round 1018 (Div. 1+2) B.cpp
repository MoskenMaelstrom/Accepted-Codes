// Problem: B. Wonderful Gloves
// Contest: Codeforces - Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2096/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	vector<int> a1(n),b1(n);
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a1[i];
	for(int i=0;i<n;i++) cin>>b1[i];
	
	for(int i=0;i<n;i++) {
		a[i]=max(a1[i],b1[i]);
		b[i]=min(a1[i],b1[i]);
	}
	ranges::sort(b);
	int ans=0;
	for(int i=0;i<n;i++) ans+=a[i];
	int p=n-1;
	k--;
	while (k--) {
		ans+=b[p--];
	}
	cout<<ans+1<<endl;
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









