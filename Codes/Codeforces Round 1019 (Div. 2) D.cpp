// Problem: D. Local Construction
// Contest: Codeforces - Codeforces Round 1019 (Div. 2)
// URL: https://codeforces.com/contest/2103/problem/D
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
	int n;
	cin>>n;
	vector<int> a(n),ans(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int c1=1,c2=n;
	int ed=*max_element(a.begin(),a.end());
	for(int k=1;k<=ed;k++) {
		int pos;
		for(int i=0;i<n;i++) {
			if (a[i] > k or a[i] == -1) {pos=i;break;}
		}
		if (k%2 == 1) {
			for(int i=0;i<pos;i++) if (a[i] == k) ans[i]=c2--;
			for(int i=n-1;i>pos;i--) if (a[i] == k) ans[i]=c2--;
		}
		else {
			for(int i=0;i<pos;i++) if (a[i] == k) ans[i]=c1++;
			for(int i=n-1;i>pos;i--) if (a[i] == k) ans[i]=c1++;
		}
	}
	int pos=find(a.begin(),a.end(),-1)-a.begin();
	ans[pos]=c1++;
	for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i == n-1];
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









