// Problem: Matrix (matrix)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108307/I
// Memory Limit: 512 MB
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
	int n,m;
	cin>>n>>m;
	if (gcd(n,m) != 1) {cout<<"NO\n";return;}
	
	vector a(n,vector<int>(m));
	
	int x=0;
	int y=0;
	int p=1;
	int cnt=0;
	while (cnt != n) {
		int cnt2=0;
		while (cnt2 != m) {
			if (cnt2%2 == 0) {
				a[x][y]=p;
				y=((y+p)%m+m)%m;
				p++;
			}
			else {
				a[x][y]=p;
				y=((y-p)%m+m)%m;
				p++;
			}
			cnt2++;
		}
		if (cnt%2 == 1) {
			x=((x+(p-1))%n+n)%n;
		}
		else x=((x-(p-1))%n+n)%n;
		cnt++;
	}
	
	cout<<"YES\n";
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
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









