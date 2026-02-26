// Problem: Loopy Laggon
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108304/A
// Memory Limit: 2048 MB
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
	int id,m,k,n;
	cin>>id>>m>>k>>n;
	while (m--) {
		int ok=0;
		for(int i=0;i<k;i++) {
			vector a(n,vector<int>(n));
			for(int x=0;x<n;x++) {
				for(int y=0;y<n;y++) {
					cin>>a[x][y];
				}
			}
			
			auto check=[&](int x,int y) -> bool {
				int cnt=0;
				int a1=a[x][y],a2=a[x][y+1],a3=a[x+1][y],a4=a[x+1][y+1];
				if (a1+1 == a2 or a2+1 == a4 or a4+1 == a3 or a3+1 == a1) cnt++;
				if (a3+1 == a4 or a1+1 == a3 or a2+1 == a1 or a4+1 == a2) cnt++;
				if (a1+n == a3 or a2+n == a1 or a4+n == a2 or a3+n == a4) cnt++;
				// cout<<cnt<<endl;
				if (cnt == 3) return 1;	
				return 0;
			};
			 
			for(int x=0;x<n-1;x++) {
				for(int y=0;y<n-1;y++) {
					if (check(x,y)) ok=1;
				}
			}
		}
		
		if (ok) cout<<0;
		else cout<<1;
	}
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









