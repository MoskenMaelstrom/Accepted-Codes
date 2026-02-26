// Problem: C. Kevin and Puzzle
// Contest: Codeforces - IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2061/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),l(n),h(n);
	for(auto &e1 : a) cin>>e1;
	if (a[0] == 0) {
		l[0]=h[0]=1;
	}
	else {
		h[0]=0;
		l[0]=1;
	}
	
	for(int i=1;i<n;i++) {	
		l[i]=h[i-1];
		if (a[i] == a[i-1]) {
			h[i]+=h[i-1];
		}
		if (i >= 2 and a[i-2] == a[i]-1) h[i]+=l[i-1];
		if (i == 1 and a[i] == 1) h[i]+=l[i-1];
		
		h[i]%=p;
		l[i]%=p;
	}
	cout<<(h[n-1]+l[n-1])%p<<endl;
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









