// Problem: I. Bingo 3
// Contest: Codeforces - 2025 ICPC Wuhan Invitational Contest (The 3rd Universal Cup. Stage 37: Wuhan)
// URL: https://codeforces.com/gym/105901/problem/I
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	if (k < n or k > n*n-n+1) {cout<<"No\n";return;}
	vector a(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		a[i][i]=k++;
	}
	int m=1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (a[i][j]) continue;
			a[i][j]=m++;
			if (m == k-n) m+=n;
		}
	}
	cout<<"Yes\n";
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
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







