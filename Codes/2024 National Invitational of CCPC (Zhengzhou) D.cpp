// Problem: D. 距离之比
// Contest: Codeforces - 2024 National Invitational of CCPC (Zhengzhou), 2024 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105158/problem/D
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	double ans=0;
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	
	ranges::sort(a,[&](array<int,2> A,array<int,2> B) {
		return A[0]-B[0] < A[1]-B[1];
	});
	for(int i=0;i<n-1;i++) {
		int d1=abs(a[i][0]-a[i+1][0])+abs(a[i][1]-a[i+1][1]);
		int d2=(a[i][0]-a[i+1][0])*(a[i][0]-a[i+1][0])+(a[i][1]-a[i+1][1])*(a[i][1]-a[i+1][1]);
		ans=max(ans,d1/sqrt(d2));
	}
	
	ranges::sort(a,[&](array<int,2> A,array<int,2> B) {
		return A[0]-B[0] < -A[1]+B[1];
	});
	for(int i=0;i<n-1;i++) {
		int d1=abs(a[i][0]-a[i+1][0])+abs(a[i][1]-a[i+1][1]);
		int d2=(a[i][0]-a[i+1][0])*(a[i][0]-a[i+1][0])+(a[i][1]-a[i+1][1])*(a[i][1]-a[i+1][1]);
		ans=max(ans,d1/sqrt(d2));
	}
	cout<<fixed<<setprecision(15)<<ans<<"\n";
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







