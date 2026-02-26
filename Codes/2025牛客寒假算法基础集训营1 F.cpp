// Problem: 双生双宿之探
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/F
// Memory Limit: 512 MB
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
	int n;
	cin>>n;
	vector<int> a(n),pre(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	int ans=0;
	int l=0,r=0;
	set<int> st;
	st.insert(a[r]);
	while (1) {
		while ((st.contains(a[r+1]) or st.size() <= 1) and r+1 != n) st.insert(a[++r]);
		if (st.size() != 2) break;
		int e1=*st.begin();
		int e2=*(++st.begin());
		for(int i=l;i<=r;i++) {
			if (a[i] == e1) pre[i]=1;
			else pre[i]=-1;
		}
		for(int i=l+1;i<=r;i++) pre[i]+=pre[i-1];
		
		map<int,int> mp;
		for(int i=l;i<=r;i++) mp[pre[i]]++;
		mp[0]++;
		for(auto [key,val] : mp) {
			ans+=(val)*(val-1)/2;
		}
		//退出
		if (r == n-1) break;
		
		l=r;
		while (a[l] == a[l-1] and l-1 != -1) l--;
		st.clear();
		st.insert(a[l]);
		r=l;
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









