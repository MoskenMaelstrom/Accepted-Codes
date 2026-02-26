// Problem: F. Prefix Maximum Invariance
// Contest: Codeforces - Codeforces Round 1047 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2137/F
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
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	vector<int> a1(n,-1),a2(n,-1);
	vector<int> sta;
	for(int i=0;i<n;i++) {
		while (!sta.empty() and a[sta.back()] < a[i]) {
			sta.pop_back();
		}
		if (!sta.empty()) a1[i]=sta.back();
		sta.push_back(i);
	}
	
	sta.clear();
	sta.push_back(0);
	for(int i=1;i<n;i++) {
		int lo=0,hi=sta.size()-1,res=-1;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			if (a[sta[mid]] >= b[i]) lo=mid+1,res=mid;
			else hi=mid-1;
		}
		a2[i]=res == -1 ? -1 : sta[res];
		while (!sta.empty() and a[sta.back()] < a[i]) {
			sta.pop_back();
		}
		sta.push_back(i);
	}
	
	// for(auto e1 : a1) cout<<e1<<" ";
	// cout<<endl;
	// for(auto e1 : a2) cout<<e1<<" ";
	// cout<<endl;
	int ans=0;
	for(int i=0;i<n;i++) {
		// cout<<"ans:"<<ans<<endl;
		if (a[i] > b[i]) {
			if (a1[i] == -1) continue;
			ans+=(a1[i]+1)*(n-i);
		}
		if (a[i] == b[i]) {
			ans+=(i)*(n-i)+(n-i);
		}
		if (a[i] < b[i]) {
			if (a2[i] == -1) continue;
			ans+=(a2[i]+1)*(n-i);
		}
	}
	cout<<ans<<endl;
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









