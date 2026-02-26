// Problem: 智乃的逆序数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95335/K
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector vec(n,vector<int>(0));
	for(int i=0;i<n;i++) {
		int m;
		cin>>m;
		while (m--) {
			int num;
			cin>>num;
			vec[i].push_back(num);
		}
	}
	sort(vec.begin(),vec.end(),[](vector<int> &A,vector<int> &B){
		return A[0] < B[0];
	});
	
	vector<array<int,2>> a;
	for(int i=0;i<n;i++) {
		for(auto e1 : vec[i]) a.push_back({i,e1});
	}
	n=a.size();
	
	auto calc=[&]() {
		int cnt=0;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if (a[i] > a[j]) cnt++;
			}
		}
		return cnt;
	};
	
	int ans=calc();
	if (ans == k) {
		cout<<"Yes\n";
		for(auto [e1,e2] : a) cout<<e2<<" ";return;
	}
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<i;j++) {
			if (a[j][0] == a[j+1][0] or a[j][1] > a[j+1][1]) continue;
			swap(a[j],a[j+1]);
			ans++;
			if (ans == k) {
				cout<<"Yes\n";
				for(auto [e1,e2] : a) cout<<e2<<" ";return;
			}
		}
	}
	cout<<"No";
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









