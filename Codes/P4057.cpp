// Problem: 
//     P4057 [Code+#1] 晨跑
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4057
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<lcm(lcm(a,b),c);
	return 0;
}