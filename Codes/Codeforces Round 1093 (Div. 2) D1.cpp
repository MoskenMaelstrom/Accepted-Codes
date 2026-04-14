// Problem: D1. Unique Values (Easy version)
// Contest: Codeforces - Codeforces Round 1093 (Div. 2)
// URL: https://codeforces.com/contest/2220/problem/D1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int query(vector<int>& a)
{
	cout<<"? "<<a.size()<<" ";
	for(auto e1 : a) cout<<e1<<" ";
	cout<<endl;
	int res;
	cin>>res;
	return res;
}

void solve()
{
	int n;
	cin>>n;
	int lo=1,hi=2*n+1,p=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		vector<int> cur;
		for(int i=1;i<=mid;i++) cur.push_back(i);
		int res=query(cur);
		if ((mid-res)%2) p=mid,hi=mid-1;
		else lo=mid+1;
	}
	int p3=p;
	assert(p != -1);
	
	lo=1,hi=p3-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		vector<int> cur;
		for(int i=lo;i<=mid;i++) cur.push_back(i);
		if (cur.empty()) {lo=mid+1;continue;}
		int res1=query(cur);
		cur.push_back(p3);
		int res2=query(cur);
		if (res2-res1 <= 0) p=mid,hi=mid-1;
		else lo=mid+1;
	}
	int p1=p;
	
	lo=1,hi=p3-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		vector<int> cur;
		for(int i=lo;i<=mid;i++) {
			if (i == p1) continue;
			cur.push_back(i);
		}
		if (cur.empty()) {lo=mid+1;continue;}
		int res1=query(cur);
		cur.push_back(p3);
		int res2=query(cur);
		if (res2-res1 <= 0) p=mid,hi=mid-1;
		else lo=mid+1;
	}
	int p2=p;
	
	cout<<"! "<<p1<<" "<<p2<<" "<<p3<<endl;
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







