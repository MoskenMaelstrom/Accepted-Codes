// Problem: 真白的幻觉
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/G
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
	vector<int> a={1,2,3,4,6,7,8,9};
	auto calc=[&](int num) -> int {
	    int cnt=0;
	    while (num >= 10) {
	        int nxt=1;
	        while (num > 0) {
	            nxt*=num%10;
	            num/=10;
	        }
	        num=nxt;
	        cnt++;
	    }
	    return cnt;
	};
	
	int ans=0,t=0;
	function<void(int,int)> dfs=[&](int num,int step) -> void {
		if (step == 17) {
			int cur=calc(num);
			if (t <= cur) {
				t=cur;
				ans=num;
			}
			return;
		}
		
		for(auto e1 : a) {
			if (e1 < num%10) continue;
			dfs(num*10+e1,step+1);
		}
	};
	dfs(0,0);
	cout<<11277777788888899<<" ";
	cout<<ans<<"\n";
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







