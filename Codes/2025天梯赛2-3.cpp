#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
	for(int i=0;i<n;i++) {
		string s1,s2;
		cin>>s1>>s2;
		int t1=60*60*((s1[0]-'0')*10+s1[1]-'0')+60*((s1[3]-'0')*10+s1[4]-'0')+(s1[6]-'0')*10+s1[7]-'0';
		int t2=60*60*((s2[0]-'0')*10+s2[1]-'0')+60*((s2[3]-'0')*10+s2[4]-'0')+(s2[6]-'0')*10+s2[7]-'0';
		// cout<<t1<<" "<<t2<<"\n";
		pq.push({t1,1});
		pq.push({t2+1,-1});
	}
	
	int ans=0,cur=0;
	while (!pq.empty()) {
		auto [t,opt]=pq.top();
		pq.pop();
		cur+=opt;
		ans=max(ans,cur);
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







