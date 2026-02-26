// Problem: 
//     P2866 [USACO06NOV] Bad Hair Day S
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2866
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=8e4+5;
signed main()
{
	int n,a;
	cin>>n;
	stack<int> stk;
	int ans=0;
	for(int i=1;i<=n;i++) {
		cin>>a;
		while (!stk.empty() and stk.top() <= a) stk.pop();
		if (stk.empty()) {stk.push(a);continue;}
		if (stk.top() >= a) {ans+=stk.size();stk.push(a);}
	}
	cout<<ans;
	return 0;
}