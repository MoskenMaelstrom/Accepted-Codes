// Problem: F. Download Speed Monitor
// Contest: Codeforces - 2024 Jiangsu Collegiate Programming Contest
// URL: https://codeforces.com/gym/105161/problem/F
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	queue<int> q;
	int ans=0;
	for(int i=0;i<k-1;i++) q.push(a[i]),ans+=a[i];
	for(int i=k-1;i<n;i++) {
		q.push(a[i]);
		ans+=a[i];
		double res=(double)ans/k;
		if (res > 1024) cout<<fixed<<setprecision(6)<<res/1024<<" MiBps\n";
		else cout<<fixed<<setprecision(6)<<res<<" KiBps\n";
		q.pop();
		ans-=a[i-k+1];
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







