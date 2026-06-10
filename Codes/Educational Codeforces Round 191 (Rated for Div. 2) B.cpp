// Problem: B. Different Distances
// Contest: Codeforces - Educational Codeforces Round 191 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2233/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int a[]={0,1,1,0,0,1,0,1};
int b[]={0,0,1,0,1,2,0,2,1,1,2,2};
void solve()
{
	int n;
	cin>>n;
	if (n&1) {
		cout<<"1 1 2 1 2 3 1 3 2 2 3 3 ";
		for(int i=4;i<=n;i+=2) {
			for(auto x : a) {
				cout<<i+x<<" ";
			}
		}
	}
	else {
		for(int i=1;i<=n;i+=2) {
			for(auto x : a) {
				cout<<i+x<<" ";
			}
		}
	}
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







