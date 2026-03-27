#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,l,r;
	cin>>n>>l>>r;
	queue<int> q;
	q.push(0);
	for(int i=1;i<=n;i++) {
		queue<int> cur;
		while (!q.empty()) {
			auto k=q.front();
			q.pop();
			if (i > 1 and k == 0) continue;
			for(int j=0;j<=9;j++) {
				int num=k*10+j;
				if (num%i == 0) cur.push(num);
			}
		}
		q=cur;
	}
	
	vector<int> ans;
	while (!q.empty()) {
		int k=q.front();
		if (l <= k and k <= r) ans.push_back(k);
		q.pop();
	}
	ranges::sort(ans);
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	if (ans.empty()) cout<<"No Solution\n";
	else {
		for(auto x : ans) cout<<x<<"\n";
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







