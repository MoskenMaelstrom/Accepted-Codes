// Problem: 
//     P1059 [NOIP2006 普及组] 明明的随机数
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1059
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n,a;
	set<int> st;
	cin>>n;
	while (n--) {
		cin>>a;
		st.insert(a);
	}
	cout<<st.size()<<endl;
	for(auto ele : st) cout<<ele<<" ";
	return 0;
}