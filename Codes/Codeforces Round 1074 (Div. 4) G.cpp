// Problem: G. Mixing MEXes
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/G
// Memory Limit: 256 MB
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
	map<int,int> cnt;
	vector a(n,vector<int>(0));
	int t=0;
	
	for(int i=0;i<n;i++) {
		int len;
		cin>>len;
		a[i].resize(len);
		for(int j=0;j<len;j++) {
			cin>>a[i][j];
			cnt[a[i][j]]++;
		}
		t+=len;
		ranges::sort(a[i]);
	}
	
	int sum=0;
	vector<int> m1(n),m2(n);
	for(int i=0;i<n;i++) {
		int cur=0;
		for(auto x : a[i]) {
			if (x == cur) cur++;
		}
		m1[i]=cur;
		sum+=cur;
		
		cur++;
		for(auto x : a[i]) {
			if (x == cur) cur++;
		}
		m2[i]=cur;
	}
	
	int ans=t*(n-1)*sum;
	for(int i=0;i<n;i++) {
		for(int j=0;j<a[i].size();j++) {
			if (a[i][j] < m1[i]) {
				if (j > 0 and a[i][j-1] == a[i][j] or j+1 < a[i].size() and a[i][j] == a[i][j+1]) continue;
				ans-=(m1[i]-a[i][j])*(n-1);
			}
		}
	}
	
	for(int i=0;i<n;i++) {
		if (cnt[m1[i]] > 0) ans+=cnt[m1[i]]*(m2[i]-m1[i]);
	}
	cout<<ans<<"\n";
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







