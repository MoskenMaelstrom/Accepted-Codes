// Problem: D - Long Waiting
// Contest: AtCoder - AtCoder Beginner Contest 423
// URL: https://atcoder.jp/contests/abc423/tasks/abc423_d
// Memory Limit: 1024 MB
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
	int n,k;
	cin>>n>>k;
	vector<array<int,3>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	ranges::sort(a);
	
	multiset<array<int,2>> st;
	int sum=0,cur=0;
	for(int i=0;i<n;i++) {
		auto [A,B,C]=a[i];
		while (1) {
			while (!st.empty()) {
				auto [time,num]=*st.begin();
				if (time <= cur) {
					st.erase(st.begin());
					sum-=num;
				}
				else break;     
			}
			if (sum+C <= k and cur >= A) {
				st.insert({cur+B,C});
				sum+=C;
				cout<<cur<<"\n";
				break;
			}
			
			auto [time,num]=*st.begin();
			if (sum+C > k) cur=time;
			else cur=A;
		}
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









