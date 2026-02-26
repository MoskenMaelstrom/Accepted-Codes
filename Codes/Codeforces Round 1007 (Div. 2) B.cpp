// Problem: B. Perfecto
// Contest: Codeforces - Codeforces Round 1007 (Div. 2)
// URL: https://codeforces.com/contest/2071/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
bool pd(int num)
{
	int q=sqrt(num);
	return (q*q == num);
}

void solve()
{
	int n;
	cin>>n;
	if (pd(n*(n+1)/2)) {cout<<-1<<endl;return;}
	
	vector<int> a(n);
	for(int i=1;i<=n;i++) {
		a[i-1]=i;
	}
	
	int sum=0;
	int p=0;
	while (1) {
		if (p == n-1) break;
		if (pd(sum+a[p])) swap(a[p],a[p+1]);
		sum+=a[p];
		p++;
	}
	for(auto ele : a) cout<<ele<<" ";
	cout<<"\n";
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









