// Problem: C. Monopati
// Contest: Codeforces - Codeforces Round 1063 (Div. 2)
// URL: https://codeforces.com/contest/2163/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector vec(2,vector<int>(n));
	for(int i=0;i<2;i++) {
		for(int j=0;j<n;j++) {
			cin>>vec[i][j];
		}
	}
	vector<int> a0(n),a1(n);
	a0[0]=vec[0][0];
	a1[0]=vec[0][0];
	for(int j=1;j<n;j++) {
		a0[j]=min(a0[j-1],vec[0][j]);
		a1[j]=max(a1[j-1],vec[0][j]);
	}
	
	vector<int> b0(n),b1(n);
	b0[n-1]=vec[1][n-1];
	b1[n-1]=vec[1][n-1];
	for(int j=n-2;j>=0;j--) {
		b0[j]=min(b0[j+1],vec[1][j]);
		b1[j]=max(b1[j+1],vec[1][j]);
	}
	
	vector<int> L(n),R(n);
	for(int j=0;j<n;j++) {
		L[j]=min(a0[j],b0[j]);
		R[j]=max(a1[j],b1[j]);
	}
	
	vector A(2*n+1,vector<int>(0));
	for(int j=0;j<n;j++) {
		A[L[j]].push_back(R[j]);
	}
	
	int ans=0,cur=2*n+1;
	for(int l=2*n;l>=1;l--) {
		for(auto r : A[l]) cur=min(cur,r);
		int R=max(l,cur);
		if (R <= 2*n) ans+=2*n-R+1;
	}
	cout<<ans<<"\n";
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







