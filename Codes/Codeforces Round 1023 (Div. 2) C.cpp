// Problem: C. Maximum Subarray Sum
// Contest: Codeforces - Codeforces Round 1023 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2107/C
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

const int inf=1e18;
int get(vector<int>& a) {
	int sum=-inf;
	int res=-inf;
	for(auto& e1 : a) {
		sum=max(0ll,sum)+e1;
		res=max(res,sum);
	}
	return res;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (s[i] == '0') a[i]=-inf;
	}
	int res=get(a);
	if (res > k) {
		cout<<"NO\n";
	}
	else if (res == k) {
		cout<<"YES\n";
		for(auto& e1 : a) cout<<e1<<" ";
		cout<<"\n";
	}
	else {
		int x=s.find('0');
		if (x == -1) cout<<"NO\n";
		else {
			a[x]=inf;
			res=get(a);
			a[x]+=-res+k;
			cout<<"YES\n";
			for(auto& e1 : a) cout<<e1<<" ";
			cout<<"\n";
		}
	}
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









