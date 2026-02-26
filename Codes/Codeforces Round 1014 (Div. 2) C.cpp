// Problem: C. Asuna and the Mosquitoes
// Contest: Codeforces - Codeforces Round 1014 (Div. 2)
// URL: https://codeforces.com/contest/2092/problem/C
// Memory Limit: 256 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	ranges::sort(a);
	int ele=a[n-1];
	int a1=0,a2=0;
	int sum1=0,sum2=0;
	for(int i=0;i<n-1;i++) {
		if (a[i]%2 == 0) {a2++;sum2+=a[i];}
		else {a1++;sum1+=a[i];}
	}
	
	//偶数
	if (ele%2 == 0) {
		if (a1 == 0) cout<<ele<<endl;
		else {
			if (a2 == 0) {
				cout<<ele+sum1-a1+1<<endl;
			}
			else {
				cout<<ele+sum1+sum2-a1+1<<endl;
			}
		}
	}
	if (ele%2 == 1) {
		if (a2 == 0) cout<<ele<<endl;
		else {
			if (a1 == 0) {
				cout<<ele+sum2<<endl;
			}
			else {
				cout<<ele+sum1+sum2-a1<<endl;
			}
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









