// Problem: D - 183183
// Contest: AtCoder - AtCoder Beginner Contest 433
// URL: https://atcoder.jp/contests/abc433/tasks/abc433_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int get(int num) {
	return to_string(num).size();
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<unordered_map<int,int>> cnt(11);
	
	for(int i=0;i<n;i++) {
		int p=10;
		for(int k=1;k<=10;k++) {
			cnt[k][a[i]*p%m]++;
			p*=10;
			p%=m;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		int len=get(a[i]);
		int aj=a[i]%m;
		int tar=(m-aj)%m;
		ans+=cnt[len][tar];
	}
	cout<<ans;
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







