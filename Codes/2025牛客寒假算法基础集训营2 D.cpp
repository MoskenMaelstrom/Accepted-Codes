// Problem: 字符串里串
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95334/D
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
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
	int n,ans=-1;
	cin>>n;
	string s;
	cin>>s;
	
	set<int> st;
	for(int i=n-1;i>0;i--) {
		int k=st.size();
		st.insert(s[i]);
		if (st.contains(s[i-1])) {ans=i;break;}
	}
	
	ranges::reverse(s);
	st.clear();
	for(int i=n-1;i>0;i--) {
		int k=st.size();
		st.insert(s[i]);
		if (st.contains(s[i-1])) {ans=max(ans,i);break;}
	}
	
	if (ans > 1) cout<<ans;
	else cout<<0;
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









