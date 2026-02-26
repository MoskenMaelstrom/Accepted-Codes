// Problem: C. The Nether
// Contest: Codeforces - Codeforces Round 1044 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2133/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> res(n+1);
	for(int i=1;i<=n;i++) {
		cout<<"? "<<i<<" "<<n<<" ";
		for(int j=1;j<=n;j++) cout<<j<<" ";
		cout<<endl; 
		cin>>res[i];
	}
	
	queue<array<int,2>> q;
	vector<int> ans;
	q.push({ranges::max_element(res)-res.begin(), *ranges::max_element(res)});
	while (!q.empty()) {
		auto [u,dist]=q.front();
		q.pop();
		ans.push_back(u);
		if (dist == 1) break;
		
		vector<array<int,2>> vec;
		for(int i=1;i<=n;i++) {
			if (res[i] == dist-1) vec.push_back({i,res[i]});
		}
		for(auto [v,w] : vec) {
			cout<<"? "<<u<<" 2 "<<u<<" "<<v<<endl;
			int d;
			cin>>d;
			if (d == 2) {q.push({v,w});break;}
		}
	}
	
	cout<<"! "<<ans.size()<<" ";
	for(auto e1 : ans) cout<<e1<<" ";
	cout<<endl;
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









