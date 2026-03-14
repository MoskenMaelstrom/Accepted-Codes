// Problem: D. Dreamoon and Sets
// Contest: Codeforces - Codeforces Round 272 (Div. 2)
// URL: https://codeforces.com/problemset/problem/476/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	cout<<(6*n-1)*k<<"\n";
	for(int i=0;i<n;i++) {
		cout<<(6*i+1)*k<<" "<<(6*i+2)*k<<" "<<(6*i+3)*k<<" "<<(6*i+5)*k<<"\n";
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







