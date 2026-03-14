// Problem: M. Many CF Rounds vs Capoo
// Contest: Codeforces - The 6th Liaoning Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106380/problem/M
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	sort(a.begin(),a.end(),[&](const array<int,2>& A,const array<int,2>& B){
		int mx1=max(A[0],A[1]);
		int mx2=max(B[0],B[1]);
		if (mx1 == mx2) return A[0] < B[0];
		else return mx1 < mx2;
	});
	
	int x=0,ans=0;
	for(int i=0;i<n;i++) {
		if (x <= a[i][0]) ans++,x=max(x,a[i][1]); 
	}
	cout<<ans<<"\n";
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







