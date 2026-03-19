// Problem: B. Twin Guardians
// Contest: Codeforces - 2025 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/106084/problem/B
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=1e6;
vector<bool> isp(N+1,1);
void solve()
{
	int a,b;
	cin>>a>>b;
	if (a+2 != b or !isp[a] or !isp[b]) cout<<"N\n";
	else cout<<"Y\n";
}

signed main()
{
	isp[0]=isp[1]=0;
	for(int i=2;i<=N;i++) {
		if (!isp[i]) continue;
		for(int j=i;i*j<=N;j++) isp[i*j]=0;
	}
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







