// Problem: E. Adjusting Drones
// Contest: Codeforces - Codeforces Round 1066 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2157/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> cnt(4*n+1);
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		cnt[num]++;
	}
	
	n=4*n;
	vector<int> sta;
	int ans=0;
	for(int i=n;i>=1;i--) {
		if (cnt[i] == 0) {sta.push_back(i);continue;}
		int m=cnt[i]-1;
		int rest=max(0ll,cnt[i]-k);
		while (m) {
			int id=sta.back();
			sta.pop_back();
			if (rest) {
				ans=max(ans,id-i);
				rest--;
			}
			m--;
		}
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







