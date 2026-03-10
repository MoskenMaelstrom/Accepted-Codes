// Problem: G. 矩阵
// Contest: Codeforces - The 2025 Shanghai Collegiate Programming Contest
// URL: https://codeforces.com/gym/105992/problem/G
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=2e6;
void solve()
{
	vector<bool> isp(N+1,1);
	isp[0]=isp[1]=0;
	for(int i=2;i<=N;i++) {
		if (!isp[i]) continue;
		for(int j=i;i*j<=N;j++) isp[i*j]=0;
	}
	int n;
	cin>>n;
	int p;
	for(int i=n+1;;i++) {
		if (isp[i]) {p=i;break;}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<i*p+j<<" ";
		}
		cout<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







