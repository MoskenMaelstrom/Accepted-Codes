// Problem: C. Odd Process
// Contest: Codeforces - Codeforces Round 1070 (Div. 2)
// URL: https://codeforces.com/contest/2176/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a,b;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		if (num%2 == 0) a.push_back(num);
		else b.push_back(num);
	}
	ranges::sort(a,greater<int>());
	ranges::sort(b,greater<int>());
	int n0=a.size();
	int n1=b.size();
	if (n1 == 0) {
		for(int i=0;i<n;i++) cout<<"0 ";
		cout<<"\n";
		return;
	}
	vector<int> pre(n0+1);
	for(int i=1;i<=n0;i++) {
		pre[i]=pre[i-1]+a[i-1];
	}
	int p=(n1%2 == 0 ? n-1 : n);
	for(int k=1;k<=n;k++) {
		if (k > p) {
			cout<<"0 ";
			continue;
		} 
		int x=min(k-1,n0);
		if (x == n0 and (k-x-1)%2 != 0) x--;
		
		if (x < 0) cout<<"0 ";
		else cout<<b[0]+pre[x]<<" ";
	}
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




