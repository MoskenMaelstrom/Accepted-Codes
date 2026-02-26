// Problem: 
//     P4305 [JLOI2011] 不重复数字
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4305
// Memory Limit: 125 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	int n,a;
	set<int> s;
	cin>>n;
	rep(i,n){
		cin>>a;
		if (s.find(a) == s.end()) {cout<<a<<" ";s.insert(a);}
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
