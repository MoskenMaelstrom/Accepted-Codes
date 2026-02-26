// Problem: D. Scammy Game Ad
// Contest: Codeforces - Codeforces Round 1008 (Div. 2)
// URL: https://codeforces.com/contest/2078/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n),b(n);
	for(int i=0;i<n;i++) {
		char o1,o2;
		cin>>o1>>a[i][1]>>o2>>b[i][1];
		if (o1 == '+') a[i][0]=0;
		else a[i][0]=1;
		if (o2 == '+') b[i][0]=0;
		else b[i][0]=1;
	}
	
	int l=1,r=1;
	int cnt;
	auto worka=[&](int pos,int x) -> int {
		if (a[pos][0] == 0) return a[pos][1];
		else return x*a[pos][1]-x;
	};
	auto workb=[&](int pos,int x) -> int {
		if (b[pos][0] == 0) return b[pos][1];
		else return x*b[pos][1]-x;
	};
	
	
	vector<int> opt(n);//第i个值代表i~i+1的路选谁(0指l,1指r),第n-1个值为空
	for(int i=n-1;i>0;i--) {
		if (a[i][0] == 1 and b[i][0] == 1) {
			if (a[i][1] > b[i][1]) opt[i-1]=0;
			if (a[i][1] < b[i][1]) opt[i-1]=1;
			if (a[i][1] == b[i][1]) opt[i-1]=opt[i];
		}
		else if (a[i][0] == 1 and b[i][0] == 0) {
			opt[i-1]=0;
		}
		else if (a[i][0] == 0 and b[i][0] == 1) {
			opt[i-1]=1;
		}
		else opt[i-1]=opt[i];
	}
	for(int i=0;i<n;i++) {
		cnt=worka(i,l)+workb(i,r);
		if (opt[i] == 0) l+=cnt;
		else r+=cnt;
	}
	cout<<l+r<<endl;
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









