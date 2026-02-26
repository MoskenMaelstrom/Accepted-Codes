// Problem: 本场比赛灵感来源于树状数组出题组
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/A
// Memory Limit: 512 MB
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	map<int,int> mp;
	for(int i=0;i<n;i++) mp[a[i]]++;
	
	int sum=0,cnt=0;
	for(auto [num,c] : mp) {
		cnt+=c;
		if ((cnt-1)*10 >= 8*(n-1)) sum+=num*c;
	}
	cout<<sum;
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







