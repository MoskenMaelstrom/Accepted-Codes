// Problem: C. Incremental Stay
// Contest: Codeforces - Codeforces Round 1053 (Div. 2)
// URL: https://codeforces.com/contest/2151/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n*2+1);
	for(int i=1;i<=2*n;i++) cin>>a[i];
	
	vector<int> cha0(n+1);
	for(int i=1;i<=n;i++) {
		cha0[i]=a[2*i]-a[2*i-1];
		cha0[i]+=cha0[i-1];
	}
	vector<int> cha1(n+1);
	for(int i=1;i<=n-1;i++) {
		cha1[i]=a[2*i+1]-a[2*i];
		cha1[i]+=cha1[i-1];
	}
	
	vector<int> pre(n*2+1);
	for(int i=1;i<=2*n;i++) {
		pre[i]=pre[i-1]+a[i];
	}
	
	for(int k=1;k<=n;k++) {
		if (k%2 == 1) cout<<(pre[2*n]-pre[2*n-k+1])-pre[k-1]+cha0[n-(k-1)/2]-cha0[(k-1)/2]<<" ";
		else cout<<(pre[2*n]-pre[2*n-k+1])-pre[k-1]+cha1[n-(k+1)/2]-cha1[(k-1)/2]<<" ";
	}
	cout<<"\n";
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









