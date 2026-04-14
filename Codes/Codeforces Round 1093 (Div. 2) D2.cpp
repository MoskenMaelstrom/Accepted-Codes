// Problem: D2. Unique Values (Hard version)
// Contest: Codeforces - Codeforces Round 1093 (Div. 2)
// URL: https://codeforces.com/contest/2220/problem/D2
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
	vector<int> a;
	for(int k=0;k<3;k++) {
		int lo=1,hi,res=-1;
		if (a.empty()) hi=2*n+1;
		else hi=a.back()-1;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			auto vec=a;
			for(int i=1;i<=mid;i++) vec.push_back(i);
			if (query(vec)%2 != vec.size()%2) res=mid,hi=mid-1;
			else lo=mid+1;
		}
		assert(res != -1);
		a.push_back(res);
	}
	cout<<"! "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
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







