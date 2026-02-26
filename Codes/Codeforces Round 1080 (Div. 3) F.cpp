// Problem: F. Parabola Independence
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

bool calc(const array<int,4>& f,const array<int,4>& g) {
	int A=g[0]-f[0];
	int B=g[1]-f[1];
	int C=g[2]-f[2];
	
	if (A == 0) {
		if (B != 0) return 0;
		return C > 0;
	}
	else return B*B-4*A*C < 0;
}

void solve()
{
	int n;
	cin>>n;
	vector<array<int,4>> vec(n);
	for(int i=0;i<n;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		vec[i]={a,b,c,i};
	}
	ranges::sort(vec);
	
	vector<int> L(n,1);
	vector<int> R(n,1);
	for(int i=0;i<n;i++) {
		for(int j=0;j<i;j++) {
			if (calc(vec[j],vec[i])) L[i]=max(L[i],L[j]+1);
		}
	}
	
	for(int i=n-1;i>=0;i--) {
		for(int j=i+1;j<n;j++) {
			if (calc(vec[i],vec[j])) R[i]=max(R[i],R[j]+1);
		}
	}
	
	vector<int> ans(n);
	for(int i=0;i<n;i++) ans[vec[i][3]]=L[i]+R[i]-1;
	for(auto e1 : ans) cout<<e1<<" ";
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







