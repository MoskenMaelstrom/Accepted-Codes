// Problem: C1. Cirno and Number (Easy Version)
// Contest: Codeforces - Codeforces Round 1098 (Div. 2)
// URL: https://codeforces.com/contest/2228/problem/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int c,n;
	cin>>c>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	string s=to_string(c);
	vector<int> a;
	for(int i=0;i<s.size();i++) {
		a.push_back(s[i]-'0');
	}
	int cnt=a.size();
	int ans=inf;

	auto dfs=[&](auto&& self,int id,int cur,int ok) {
		if (id == cnt) {
			ans=min(ans,abs(c-cur));
			return;
		}
		
		if (ok == 1) {
			for(int i=id;i<cnt;i++) cur=cur*10,cur+=vec[0];
			ans=min(ans,abs(c-cur));
			return;
		}
		
		if (ok == -1) {
			for(int i=id;i<cnt;i++) cur=cur*10,cur+=vec[n-1];
			ans=min(ans,abs(c-cur));
			return;
		}
		
		for(int i=0;i<n;i++) {
			if (vec[i] > a[id]) self(self,id+1,cur*10+vec[i],1);
			else if (vec[i] < a[id]) self(self,id+1,cur*10+vec[i],-1);
			else self(self,id+1,cur*10+vec[i],0);
		}
	};
	dfs(dfs,0,0,0);
	
	if (cnt != 1) {
		int num=0;
		for(int i=0;i<cnt-1;i++) {
			num*=10;
			num+=vec[n-1];
		}
		ans=min(ans,abs(c-num));
	}
	
	int num=0;
	if (vec[0] == 0) {
		num=vec[1];
		for(int i=1;i<cnt+1;i++) num*=10,num+=vec[0];
	}
	else {
		for(int i=0;i<cnt+1;i++) num*=10,num+=vec[0];
	}
	ans=min(ans,abs(c-num));
	
	cout<<ans<<"\n";
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







