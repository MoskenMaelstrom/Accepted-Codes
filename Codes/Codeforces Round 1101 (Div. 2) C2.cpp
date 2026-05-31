// Problem: C2. Seating Arrangement (Hard Version)
// Contest: Codeforces - Codeforces Round 1101 (Div. 2)
// URL: https://codeforces.com/contest/2232/problem/C2
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

void solve()
{
	int n,x,s;
	cin>>n>>x>>s;
	string a;
	cin>>a;
	int sum0=x;
	int sum1=0;
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (a[i] == 'I' and sum0) {
			sum0--;
			sum1+=s-1;
		}
		
		if (a[i] == 'E' and sum1) sum1--;
		else if (a[i] == 'E' and cnt and sum0) {
			sum0--;
			sum1+=s-1;
			cnt--;
		}
		
		if (a[i] == 'A' and sum1) {
			sum1--;
			cnt++;
		}
		else if (a[i] == 'A' and sum0) {
			sum0--;
			sum1+=s-1;
		}
	}
	cout<<s*x-sum0*s-sum1<<"\n";
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







