// Problem: 
//     P2032 扫描
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2032
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++) cin>>a[i];
	multiset<int> st;
	
	for(int i=1;i<=k;i++) st.insert(a[i]);
	cout<<*(--st.end())<<endl;
	for(int i=k+1;i<=n;i++) {
		st.insert(a[i]);
		auto it=st.find(a[i-k]);
		st.erase(it);
		cout<<*(--st.end())<<endl;
	}
	return 0;
}