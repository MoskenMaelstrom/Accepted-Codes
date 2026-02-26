// Problem: P1091 [NOIP 2004 提高组] 合唱队形
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1091
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &ele : a) cin>>ele;
	
	vector<int> b(n,1);
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) {
			if (a[j] < a[i]) b[i]=max(b[i],b[j]+1);
		}
	}
	
	vector<int> c(n,1);
	for(int i=n-2;i>=0;i--) {
		for(int j=n-1;j>i;j--) {
			if (a[j] < a[i]) c[i]=max(c[i],c[j]+1);
		}
	}
	
	int ans=1000;
	for(int i=0;i<n;i++) {
		int p=i;
		ans=min(ans,p-b[i]+n-p-c[i]);
	}
	cout<<ans+1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









