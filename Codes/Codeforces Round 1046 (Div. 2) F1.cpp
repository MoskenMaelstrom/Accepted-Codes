// Problem: F1. From the Unknown (Easy Version)
// Contest: Codeforces - Codeforces Round 1046 (Div. 2)
// URL: https://codeforces.com/contest/2136/problem/F1
// Memory Limit: 512 MB
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

const int N=1e5;
void solve()
{
	int m;
	vector<int> a(N,1);
	cout<<"? "<<N<<" ";
	for(int i=0;i<N;i++) cout<<a[i]<<" ";
	cout<<endl;
	cin>>m;
	
	if (m == 1) {
		cout<<"! "<<N<<endl;
		return;
	}
	
	
	int l=(N+m-1)/m;
	int r=N/(m-1)-(N%(m-1) == 0);
	
	vector<int> b;
	b.push_back(l);
	for(int i=l+1;i<=r;i++) {
		b.push_back(l);
		b.push_back(i-l);
	}
	cout<<"? "<<b.size()<<" ";
	for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
	
	cout<<endl;
	cin>>m;
	
	int num=r-l+1;
	int cha=m-num;
	int ans=r-cha;
	cout<<"! "<<ans<<endl;
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









