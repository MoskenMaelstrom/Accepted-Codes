// Problem: Ad-hoc Newbie
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108300/A
// Memory Limit: 1024 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector b(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		b[i][i]=1;
		for(int j=i+1;j<n;j++) {
			b[i][j]=b[j][i]=i+2;
		}
	}
	
	for(int i=0;i<n;i++) {
		int j=a[i];
		if (j == 1) b[i][i]=0;
		else b[i][j-2]=b[j-2][i]=0;
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<b[i][j]<<" \n"[j == n-1];
		}
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









