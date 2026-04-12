// Problem: I. 王国------求策
// Contest: Codeforces - The 2025 CCPC National Invitational Contest (Northeast), The 19th Northeast Collegiate Programming Contest
// URL: https://codeforces.com/gym/105924/problem/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,s,t;
	cin>>n>>s>>t;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		a[i]=x;
	}
	
	if (s > t) swap(s,t);
	if (s == t) {
		cout<<"Yes\n";
		return;
	}
	if (n == 1) {
		cout<<"No\n";
		return;
	}
	if (n == 2) {
		if (s == 1 and t == 2 or s == 3 and t == 4) {
			cout<<"No\n";
		}
		if (s == 1 and t == 3) {
			if (a[s] != t) cout<<"Yes\n";
			else cout<<"No\n";
		}
		if (s == 1 and t == 4) {
			if (a[s] != t) cout<<"Yes\n";
			else cout<<"No\n";
		}
		if (s == 2 and t == 3) {
			if (a[s] != t) cout<<"Yes\n";
			else cout<<"No\n";
		}
		if (s == 2 and t == 4) {
			if (a[s] != t) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	else {
		if (t <= n or s > n or t != a[s]) cout<<"Yes\n";
		else cout<<"No\n";
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







