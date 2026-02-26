// Problem: K. Kind of Bingo
// Contest: Codeforces - The 2024 ICPC Asia Hangzhou Regional Contest (The 3rd Universal Cup. Stage 25: Hangzhou)
// URL: https://codeforces.com/gym/105657/problem/K
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> cnt(n);
	vector<int> a(n*m);
	for(int i=0;i<n*m;i++) cin>>a[i],a[i]--;
	for(int i=0;i<n*m;i++) {
		int p=a[i];
		cnt[p/m]++;
		if (m-cnt[p/m] <= k) {cout<<max(m,i+1)<<"\n";return;}
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







