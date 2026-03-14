// Problem: L. Leak
// Contest: Codeforces - The 6th Liaoning Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106380/problem/L
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a1(n+1),a2(n+1);
	vector<int> t1(n+1),t2(n+1);
	vector ans(n+1,vector<int>(n+1,-1));
	for(int i=1;i<=n;i++) {
		cin>>a1[i];
		t1[a1[i]]=i;
	}
	for(int i=1;i<=n;i++) {
		cin>>a2[i];
		t2[a2[i]]=i;
	}
	
	for(int i=1;i<=n;i++) {
		int x=t1[i];
		int y=t2[i];
		for(int j=1;j<=n;j++) {
			if (ans[x][j] == -1) ans[x][j]=i-1;
		}
		for(int j=1;j<=n;j++) {
			if (ans[j][y] == -1) ans[j][y]=i-1;
		}
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) cout<<ans[i][j]<<" ";
		cout<<"\n";
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







