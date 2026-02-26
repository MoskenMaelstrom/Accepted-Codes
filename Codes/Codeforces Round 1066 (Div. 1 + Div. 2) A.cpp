// Problem: A. Dungeon Equilibrium
// Contest: Codeforces - Codeforces Round 1066 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2157/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=110;
void solve()
{
	int n;
	cin>>n;
	vector<int> tong(N);
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		tong[num]++;
	}
	
	int cnt=0;
	for(int i=0;i<N;i++) {
		if (tong[i] == 0 or tong[i] == i) continue;
		else if (tong[i] > i) cnt+=tong[i]-i;
		else cnt+=tong[i];
	}
	cout<<cnt<<"\n";
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







