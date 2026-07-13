// Problem: E. Friendly Gifts
// Contest: Codeforces - Codeforces Round 1103 (Div. 3)
// URL: https://codeforces.com/contest/2236/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]--;
	}

	vector mark(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		vector<int> cnt(n);
		int lo=n-1,hi=0;
		for(int j=i;j<n;j++) {
			if (cnt[a[j]]) break;
			cnt[a[j]]++;
			lo=min(lo,a[j]);
			hi=max(hi,a[j]);
			if (hi-lo == j-i) mark[lo][hi]=1;
		}
	}
	
	for(int len=n/2;len>0;len--) {
		for(int i=0;i<n;i++) {
			if (i+2*len-1 < n and mark[i][i+len-1] and mark[i+len][i+2*len-1]) {
				cout<<len<<"\n";
				return;
			}
		}
	}
	cout<<"0\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







