// Problem: I. Strange Sorting
// Contest: Codeforces - The 2023 ICPC Asia Jinan Regional Contest (The 2nd Universal Cup. Stage 17: Jinan)
// URL: https://codeforces.com/gym/104901/problem/I
// Memory Limit: 1024 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector<array<int,2>> ans;
	for(int i=0;i<n;i++) {
		if (a[i] == i) continue;
		for(int j=n-1;j>i;j--) {
			if (a[j] > a[i]) continue;
			ans.push_back({i,j});
			sort(a.begin()+i,a.begin()+j+1);
			break;
		}
	}
	
	cout<<ans.size()<<"\n";
	for(auto [l,r] : ans) {
		cout<<l+1<<" "<<r+1<<"\n";
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







