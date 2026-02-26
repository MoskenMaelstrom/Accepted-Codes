// Problem: 
//     唯一的雪花 Unique Snowflakes
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11572
// Memory Limit: 0 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

set<int> st;
void work(int x)
{
	auto it=st.find(x);
	st.erase(it);
}
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	st.insert(a[1]);
	int head=1,tail=2,ans=1;//默认队列里装一个了
	while (tail != n+1) {
		while (st.find(a[tail]) != st.end()) {work(a[head]);head++;}//把tail加入的时候检查一遍有无重复
		tail++;st.insert(a[tail-1]);//把a[tail-1]加入队列
		ans=max(tail-head,ans);
	}
	cout<<ans<<endl;
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