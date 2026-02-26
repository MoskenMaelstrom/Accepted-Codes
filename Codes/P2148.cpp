// Problem: P2148 [SDOI2009] E&D
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2148
// Memory Limit: 125 MB
// Time Limit: 1000 ms
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

int sg(int n1,int n2) {
	n1--,n2--;
	int num=(n1|n2);
	int ans=0;
	for(int i=0;i<64;i++) {
		if (((num>>i)&1) == 0) return i;
	}
}

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector<int> ans(n/2);
	for(int i=0;i<n/2;i++) {
		int n1=i*2;
		int n2=i*2+1;
		ans[i]=sg(a[n1],a[n2]);
	}
	
	int sum=0;
	for(int i=0;i<n/2;i++) {
		sum^=ans[i];
	}
	if (sum == 0) cout<<"NO\n";
	else cout<<"YES\n";
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









