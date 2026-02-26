// Problem: 小红做梦
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125955/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int x,a,b,c;    
	cin>>x>>a>>b>>c;
	int ans=inf;
	
	vector<int> pre={1005,1006,1007,1008,1009,1010};
	int cur=x;
	int cost=0;
	while (1) {
		for(auto p : pre) {
			for(int len=4;len<=17;len++) {
				int exp=1;
				for(int k=0;k<len-4;k++) exp*=10;
				int l=p*exp;
				int r=l+exp-1;
				if (r < cur) continue;
				int st=max(l,cur);
				int d=st+(cur%c-st%c+c)%c;
				if (d <= r) {
					int cnt=(d-cur)/c;
					if (cnt > (ans-cost)/b) break;
					ans=min(ans,cost+cnt*b);
				}
			}
		}
		if (cur == 0) break;
		cur/=10;
		cost+=a;
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







