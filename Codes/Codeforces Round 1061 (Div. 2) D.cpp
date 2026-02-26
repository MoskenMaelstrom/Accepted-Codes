// Problem: D. Find the Last Number
// Contest: Codeforces - Codeforces Round 1061 (Div. 2)
// URL: https://codeforces.com/contest/2156/problem/D
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
	int m=__lg(n)+1;
	vector a(n+1,vector<int>(m));
	for(int i=1;i<=n;i++) {
		for(int b=0;b<m;b++) {
			a[i][b]=((i>>b)&1);
		}
	}
	vector<int> B(m);//每位1的和
	for(int i=1;i<=n;i++) {
		for(int b=0;b<m;b++) {
			B[b]+=a[i][b];
		}
	}
	
	set<int> st;//记录剩余的idx
	for(int i=1;i<=n-1;i++) st.insert(i);
	vector<bool> ans(n+1,1);ans[0]=0;
	
	int b=0;
	while (b < m and !st.empty()) {
		int c0=0,c1=0;
		vector<int> a0,a1;
		for(auto id : st) {
			int res;
			cout<<"? "<<id<<" "<<(1<<b)<<endl;
			cin>>res;
			if (res == 0) {c0++;a0.push_back(id);}
			else {c1++;a1.push_back(id);}
		}
		
		if (c1 == B[b]) {
			for(auto e1 : a1) st.erase(e1);
			for(int i=1;i<=n;i++) {
				if (((i>>b)&1) == 1 and ans[i]) {
					ans[i]=0;
					for(int j=0;j<m;j++) B[j]-=a[i][j];
				}
			}
		}
		else {
			for(auto e1 : a0) st.erase(e1);
			for(int i=1;i<=n;i++) {
				if (((i>>b)&1) == 0 and ans[i]) {
					ans[i]=0;
					for(int j=0;j<m;j++) B[j]-=a[i][j];
				}
			}
		}
		b++;
	}
	cout<<"! "<<ranges::find(ans,1)-ans.begin()<<endl;
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









