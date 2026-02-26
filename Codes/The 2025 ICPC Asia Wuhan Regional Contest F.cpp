#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	
	multiset<array<int,3>> st;
	for(int i=0;i<q;i++) {
		int l,r;
		cin>>l>>r;
		st.insert({l,0,i});
		st.insert({r,1,i});
	}
	
	int cnt=0;
	vector<bool> mark(q);
	queue<int> que;
	for(auto [p,o,id] : st) {
		if (o == 0) que.push(id);
		else if (o == 1 and mark[id]) continue;
		else {
			cnt++;
			while (!que.empty()) {
				mark[que.front()]=1;
				que.pop();
			}
		}
	}
	
	cout<<__lg(cnt)+1<<"\n";
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







