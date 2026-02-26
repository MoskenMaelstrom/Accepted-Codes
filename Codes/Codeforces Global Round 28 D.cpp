// Problem: D. Kevin and Competition Memories
// Contest: Codeforces - Codeforces Global Round 28
// URL: https://codeforces.com/problemset/problem/2048/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	vector<int> bad;
	
	int maxn=*ranges::max_element(a);
	int num=a[0];
	for(int i=0;i<m;i++) {
		if (b[i] > num and b[i] <= maxn) bad.push_back(b[i]);
	}
	ranges::sort(bad);
	ranges::sort(a);
	vector<int> vec;
	int m1=bad.size();
	for(int i=0;i<m1;i++) {
		vec.push_back(n-(ranges::lower_bound(a,bad[i])-a.begin()));
	}
	ranges::sort(vec);
	for(int k=1;k<=m;k++) {
		int cnt=m/k;
		int out=m%k;
		if (out >= m1) {
			cout<<cnt<<" ";
		}
		else {
			int rest=m1-out;
			if (rest%k == 0) {
				int sum=cnt;
				for(int i=k-1;i<rest;i+=k) {
					sum+=vec[i];
				}
				cout<<sum<<" ";
			}
			else {
				int sum=cnt;
				for(int i=rest-1;i-k+1>=0;i-=k) {
					sum+=vec[i];
				}
				cout<<sum+vec[rest%k-1]<<" ";
			}
		}
	}
	cout<<"\n";
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









