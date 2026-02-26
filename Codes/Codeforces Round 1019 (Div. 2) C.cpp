// Problem: C. Median Splits
// Contest: Codeforces - Codeforces Round 1019 (Div. 2)
// URL: https://codeforces.com/contest/2103/problem/C
// Memory Limit: 256 MB
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
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i] <= k) b[i]=1;
		else b[i]=-1;
	}
	vector<int> pre(n+1);
	for(int i=0;i<n;i++) pre[i+1]=pre[i]+b[i];
	
	if (*max_element(pre.begin()+2,pre.end()-1) > 0) cout<<"YES\n";
	else if (count(pre.begin()+1,pre.end()-1,0) > 1) cout<<"YES\n";
	else if (pre[n]-*min_element(pre.begin()+1,pre.end()-2) > 0) cout<<"YES\n";
	else if (count(pre.begin()+1,pre.end()-1,pre[n]) > 1) cout<<"YES\n";
	else {
		int l=-1,r=-1;
		for(int i=1;i<n;i++) {
			if (pre[i] >= 0) {l=i;break;}
		}
		for(int i=n-1;i>0;i--) {
			if (pre[n]-pre[i] >= 0) {r=i+1;break;}
		}
		if (l != -1 and r != -1 and l+1 < r) cout<<"YES\n";
		else cout<<"NO\n";
	}
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









