// Problem: 
//     P1536 村村通
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1536
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int f[1005];
int fin(int x)
{
	if (x != f[x]) f[x]=fin(f[x]);
	return f[x];
}
signed main()
{
	while (1)
	{
		int n,m;
		cin>>n; if (n == 0) return 0;
		cin>>m;
		for(int i=1;i<=n;i++) f[i]=i;//初始化并查集
		
		int a1,a2;
		for(int i=0;i<m;i++) {
			cin>>a1>>a2;
			f[fin(a1)]=fin(a2);
		}
		int ans=0;
		set<int> st;
		for(int i=1;i<=n;i++)
			if (st.find(fin(i)) == st.end()) {ans++;st.insert(f[i]);}
		cout<<ans-1<<endl;
	}
	return 0;
}





