// Problem: Determinant of 01-Matrix
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108301/D
// Memory Limit: 2048 MB
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
	int d;
	cin>>d;
	int n=200;
	vector a(n,vector<int>(n));
	for(int i=0;i<n-1;i++) {
		a[i][i]=1;
	}
	a[n-1][n-1]=d;
	int row=n-1,num=1;
	while (d != 0 and a[row][n-1] != 1) {
		num=-num;
		if (a[row][n-1] > 0) d/=2;
		else d=(d+1)/2;
		row--;
		a[row][n-1]=d*num;
		row--;
		a[row][n-1]=d*num;
	}
	
	// cout<<n<<'\n';
	// for(int i=0;i<n;i++) {
		// for(int j=0;j<n;j++) {
			// cout<<a[i][j]<<" \n"[j == n-1];
		// }
	// }
	
	auto add=[&](int r1,int r2) {
		for(int j=0;j<n;j++) {
			a[r1][j]+=a[r2][j];
		}
	};
	add(n-1,n-2);
	add(n-1,n-3);
	
	row=n-2;
	while (a[row][n-1] != 0) {
		add(row,row-2);
		add(row-1,row-2);
		add(row,row-3);
		add(row-1,row-3);
		row-=2;
	}
	
	cout<<n<<'\n';
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<a[i][j]<<" \n"[j == n-1];
		}
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









