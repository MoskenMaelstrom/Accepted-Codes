// Problem: 01矩阵
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/E
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> r(n),c(n);
	for(int i=0;i<n;i++) r[i]=i;
	for(int i=0;i<n;i++) c[i]=i;
	
	if (n == 1) {cout<<"0\n";return;}
	
	bool flag=0;
	int cnt=2;
	for(int i=n-3;;i-=2) {
		if (cnt == n) break;
		for(int j=0;j<=i;j++) {
			swap(r[j],r[j+1]);
		}
		
		cnt++;
		if (cnt == n) break;
		for(int j=0;j<=i;j++) {
			swap(c[j],c[j+1]);
			if (j == 0) cnt++;
			if (cnt == n) break;
		}
		
		if (cnt == n) break;
		cnt++;
	}
	
	for(int i=0;i<n;i++) {
		vector<int> cur(n);
		for(int j=0;j<n;j++) {
			if (c[j]+r[i] < n) cur[j]=0;
			else cur[j]=1;
		}
		for(auto e1 : cur) cout<<e1;
		cout<<"\n";
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







