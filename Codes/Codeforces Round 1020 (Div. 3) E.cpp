// Problem: E. Wolf
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2106/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n),id(n);
	for(int i=0;i<n;i++) {cin>>a[i];a[i]--;}
	for(int i=0;i<n;i++) {
		id[a[i]]=i;
	}
	while (q--) {
		int l,r,k;
		cin>>l>>r>>k;
		l--,r--,k--;
		int need1=0,need2=0;
		int use1=0,use2=0;
		int idx=id[k];
		while (l <= r) {
			int mid=l+r>>1;
			if (mid == idx) break;
			if (mid > idx) {
				r=mid-1;
				if (a[mid] > k) use2++;
				else need2++;
			}
			else {
				l=mid+1;
				if (a[mid] < k) use1++;
				else need1++;
			}
		}
		if (l > r) {cout<<"-1 ";continue;}
		int t1=k,t2=n-1-k;
		if (t1-use1 >= need1 and t2-use2 >= need2) {
			if (need2 > need1) cout<<need1*2+(need2-need1)*2<<" ";
			else cout<<need2*2+(need1-need2)*2<<" ";
		}
		else cout<<"-1 ";
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









