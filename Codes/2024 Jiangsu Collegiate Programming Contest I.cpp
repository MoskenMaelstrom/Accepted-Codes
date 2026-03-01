// Problem: I. Integer Reaction
// Contest: Codeforces - 2024 Jiangsu Collegiate Programming Contest
// URL: https://codeforces.com/gym/105161/problem/I
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	int lo=2,hi=2e8,res=-1;
	auto check=[&](int x) -> bool {
		multiset<int> st0,st1;
		for(int i=0;i<n;i++) {
			if (b[i]) {
				if (st0.empty()) {st1.insert(a[i]);continue;}
				auto it=st0.lower_bound(x-a[i]);
				if (it == st0.end()) return 0;
				else st0.erase(it);
			}
			else {
				if (st1.empty()) {st0.insert(a[i]);continue;}
				auto it=st1.lower_bound(x-a[i]);
				if (it == st1.end()) return 0;
				else st1.erase(it);
			}
		}
		return 1;
	};
	
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) lo=mid+1,res=mid;
		else hi=mid-1;
	}
	cout<<res;
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







