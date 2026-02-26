// Problem: E. Power Boxes
// Contest: Codeforces - Codeforces Round 1045 (Div. 2)
// URL: https://codeforces.com/contest/2134/problem/E
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
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<int> d(n+3);
	vector<int> vec;
	
	auto th=[&](int pos) {
		int num;
		cout<<"throw "<<pos<<endl;
		cin>>num;
		return num;
	};
	auto sw=[&](int pos) {
		cout<<"swap "<<pos<<endl;
	};

	int p=n;
	while (p != 0) {
		if (d[p+1] == d[p+2]) {
			d[p]=d[p+1]+1;
		}
		else {
			d[p]=th(p);
			a[p]=d[p] == d[p+1]+1 ? 1 : 2;
		}
		p--;
	}
	
	p=1;
	while (p != n) {
		if (a[p] == 0) {
			sw(p);
			d[p+1]=th(p+1);
			a[p]=d[p+1] == d[p+2]+1 ? 1 : 2;
		}
		p++;
	}
	sw(n-1);
	d[n-1]=th(n-1);
	a[n]=d[n-1] == 1 ? 2 : 1;
	
	cout<<"! ";
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
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









