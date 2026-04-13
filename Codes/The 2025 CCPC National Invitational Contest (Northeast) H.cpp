// Problem: H. 王国------迁移
// Contest: Codeforces - The 2025 CCPC National Invitational Contest (Northeast), The 19th Northeast Collegiate Programming Contest
// URL: https://codeforces.com/gym/105924/problem/H
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
	int n;
	cin>>n;
	vector<int> a(n),b(n),c(n);
	for(int i=0;i<n;i++) {cin>>a[i];a[i]--;}
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) cin>>c[i];
	int sumb=accumulate(b.begin(),b.end(),0ll);
	
	auto check=[&](int x) -> bool {
		vector<int> d(n);
		for(int i=0;i<n;i++) d[i]=x/c[i];
		int sumd=accumulate(d.begin(),d.end(),0ll);
		if (sumb > sumd) return 0;
		for(int i=0;i<n;i++) {
			if (b[i] > sumd-d[a[i]]) return 0;
		}
		return 1;
	};
	
	int lo=0,hi=1e12,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,hi=mid-1;
		else lo=mid+1;
	}
	cout<<res<<"\n";
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







