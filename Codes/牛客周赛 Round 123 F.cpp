// Problem: 小红出牌（hard）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125954/F
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
	vector<int> cnt(n+2);
	
	int ans=0;
	for(int i=1;i<=n;i++) {
		int num;
		cin>>num;
		ans++;
		if (cnt[num-1] > cnt[num]) ans--;
		if (cnt[num+1] > cnt[num]) ans--;
		cnt[num]++;
		cout<<ans<<" ";
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







