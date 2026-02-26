// Problem: P3383 【模板】线性筛素数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3383
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
	vector<bool> isp(n+1,1);
	isp[0]=0;
	isp[1]=0;
	for(int i=2;i<=n;i++) {
		if (isp[i] == 0) continue;
		for(int j=i;i*j<=n;j++) {
			isp[i*j]=0;
		}
	}
	vector<int> ans;
	for(int i=2;i<=n;i++) {
		if (isp[i]) ans.push_back(i);
	}
	int q;
	cin>>q;
	while (q--) {
		int k;
		cin>>k;
		cout<<ans[k-1]<<endl;
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









