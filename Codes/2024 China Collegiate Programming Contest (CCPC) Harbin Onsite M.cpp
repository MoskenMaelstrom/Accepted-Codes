// Problem: C. Giving Directions in Harbin
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Harbin Onsite (The 3rd Universal Cup. Stage 14: Harbin)
// URL: https://codeforces.com/gym/105459/problem/C
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
	
	vector<int> a;
	for(int i=1;i*i<=n;i++) {
		if (n%i == 0) {
			a.push_back(i);
			if (i*i != n) a.push_back(n/i);
		}
	}
	ranges::sort(a);
	
	int sum=1;
	int m=a.size();
	for(int i=0;i<m-1;i++) {
		sum+=(a[i+1]-a[i])*(n/a[i]);
	}
	cout<<sum<<"\n";
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









