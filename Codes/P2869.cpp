// Problem: 
//     P2869 [USACO07DEC] Gourmet Grazers G
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2869
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct A {
	int p,t,kind;
} a[200050];
bool cmp(A a, A b)
{
	if (a.t == b.t) return a.kind < b.kind;//把相同口味的草放在牛前面
	else return a.t > b.t;//口味差的放后面
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {cin>>a[i].p>>a[i].t;a[i].kind=1;}
	for(int i=n+1;i<=n+m;i++) {cin>>a[i].p>>a[i].t;a[i].kind=0;}
	sort(a+1,a+n+m+1,cmp);
	
	bool flag=1;//用来判断是否满足所有要求
	multiset<int> st;
	for(int i=1;i<=n+m;i++) {
		if (a[i].kind == 0) st.insert(a[i].p);
		else {
			if (st.lower_bound(a[i].p) == st.end()) {flag=0;break;}
			else {
				ans+=*st.lower_bound(a[i].p);
				st.erase( st.lower_bound(a[i].p) );
			}
		}
	}
	
	if (flag) cout<<ans;
	else cout<<-1;
	
	return 0;
}












