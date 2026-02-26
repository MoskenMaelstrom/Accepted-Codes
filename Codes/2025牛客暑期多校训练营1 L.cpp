// Problem: Numb Numbers
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108298/L
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	int p=(n+1)/2;
	vector<int> a(n);
	map<int,int> mp;
	for(int i=0;i<n;i++) {cin>>a[i];mp[a[i]]++;}
	
	int num,l,r;//1~n
	int cnt=0;
	for(auto [e1,e2] : mp) {
		if (cnt+e2 >= (n+1)/2) {
			l=cnt+1;
			r=cnt+e2;
			num=e1;
			break;
		}
		cnt+=e2;
	}
	while (q--) {
		int idx,d;
		cin>>idx>>d;
		idx--;
		if (a[idx] == num) {
			r--;
			mp[a[idx]]--;
			if (mp[a[idx]] == 0) mp.erase(a[idx]);
			a[idx]+=d;
			mp[a[idx]]++;
			if (r < p) {
				num=mp.upper_bound(num)->first;
				l=r+1;
				r=l+mp[num]-1;
			}
		}
		else if (a[idx] < num) {
			if (a[idx]+d == num) {
				l--;
				mp[a[idx]]--;
				if (mp[a[idx]] == 0) mp.erase(a[idx]);
				a[idx]+=d;
				mp[a[idx]]++;
			}
			else if (a[idx]+d > num) {
				l--,r--;
				mp[a[idx]]--;
				if (mp[a[idx]] == 0) mp.erase(a[idx]);
				a[idx]+=d;
				mp[a[idx]]++;
				if (r < p) {
					num=mp.upper_bound(num)->first;
					l=r+1;
					r=l+mp[num]-1;
				}
			}
			else {
				mp[a[idx]]--;
				if (mp[a[idx]] == 0) mp.erase(a[idx]);
				a[idx]+=d;
				mp[a[idx]]++;
			}
		}
		else {
			mp[a[idx]]--;
			if (mp[a[idx]] == 0) mp.erase(a[idx]);
			a[idx]+=d;
			mp[a[idx]]++;
		}
		
		if (r == p) cout<<r<<'\n';
		else cout<<l-1<<'\n';
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









