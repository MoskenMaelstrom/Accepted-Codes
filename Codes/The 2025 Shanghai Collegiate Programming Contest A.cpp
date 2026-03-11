// Problem: A. 序列
// Contest: Codeforces - The 2025 Shanghai Collegiate Programming Contest
// URL: https://codeforces.com/gym/105992/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int x;
	cin>>x;
	vector<int> a;
	auto check=[&](int n) {
		int sum=(int)a.size()<<n;
		for(int i=0;i<a.size();i++) sum-=1ll<<(n-a[i]);
		return sum == x;
	};
	
	function<void(int,int)> dfs=[&](int n,int st) {
		if (check(n)) {
			cout<<"Yes\n";
			cout<<n<<"\n";
			for(int i=0;i<a.size();i++) {
				for(int j=0;j<a[i];j++) cout<<i+1<<" ";
			}
			cout<<"\n";
			exit(0);
		}
		for(int i=st;i<=62-n;i++) {
			a.push_back(i);
			dfs(n+i,i);
			a.pop_back();
		}
	};
	dfs(0,1);
	cout<<"No\n";
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







