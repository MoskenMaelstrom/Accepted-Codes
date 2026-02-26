// Problem: 小红越级（easy）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125955/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> vec(n+5);
	for(int i=0;i<n;i++) {
		int n1,n2;
		cin>>n1>>n2;
		if (n1 == n2) {
			vec[n1-1]++;
			vec[n1]++;
			vec[n1+1]++;
		}
		else if (n1 == n2-1) {
			vec[n1-1]++;
			vec[n1]++;
			vec[n1+1]++;
			vec[n1+2]++;
		}
		else if (n1 == n2-2) {
			vec[n1-1]++;
			vec[n1]++;
			vec[n1+1]++;
			vec[n1+2]++;
			vec[n1+3]++;
		}
		else {
			vec[n1-1]++;
			vec[n1]++;
			vec[n1+1]++;
			vec[n2-1]++;
			vec[n2]++;
			vec[n2+1]++;
		}
	}
	
	while (q--) {
		int x;
		cin>>x;
		cout<<n-vec[x]<<" ";
	}
	cout<<"\n";
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







