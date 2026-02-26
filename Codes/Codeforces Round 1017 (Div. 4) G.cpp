// Problem: G. Chimpanzini Bananini
// Contest: Codeforces - Codeforces Round 1017 (Div. 4)
// URL: https://codeforces.com/contest/2094/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int q;
	cin>>q;
	deque<int> que;
	
	bool rev=0;
	int sum=0,ans=0;
	while (q--) {
		int s;
		cin>>s;
		if (s == 3) {
			int c;
			cin>>c;
			if (!rev) que.push_back(c);
			else que.push_front(c);
			sum+=c;
			ans+=c*que.size();
			cout<<ans<<endl;
		}
		else if (s == 1) {
			if (!rev) {
				ans+=sum-que.size()*que.back();
				que.push_front(que.back());
				que.pop_back();
			}
			else {
				ans+=sum-que.size()*que.front();
				que.push_back(que.front());
				que.pop_front();
			}
			cout<<ans<<endl;
		}
		else {
			ans=sum*(que.size()+1)-ans;
			rev=1-rev;
			cout<<ans<<endl;
		}
	}
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









