// Problem: B. Cake Leveling
// Contest: Codeforces - Codeforces Round 1101 (Div. 2)
// URL: https://codeforces.com/contest/2232/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int cur=a[0];
	int rest=0;
	cout<<cur<<" ";
	for(int i=1;i<n;i++) {
		if (a[i] >= cur or rest >= cur-a[i]) {
			rest+=a[i]-cur;
			cout<<cur<<" ";
		}
		else {
			int dx=(cur-a[i]-rest+i)/(i+1);
			rest=rest+i*dx-(cur-dx-a[i]);
			cur-=dx;
			cout<<cur<<" ";
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







