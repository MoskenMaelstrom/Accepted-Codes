// Problem: M. Merge
// Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
// URL: https://codeforces.com/gym/105143/problem/M
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> vec(a.begin(),a.end());
	for(int i=0;i<n;i++) {
		if (a[i]%2 == 0) vec.push_back(a[i]*2-1),vec.push_back(a[i]*2+1);
	}
	ranges::sort(vec);
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	
	multiset<int> st(a.begin(),a.end());
	vector<int> b;
	auto check=[&](int x) -> bool {
		b.clear();
		bool ok=1;
		while (!st.contains(x)) {
			if (x%2 == 0) {ok=0;break;}
			int x1=x/2,x2=x-x1;
			if (x1%2 == 0) swap(x1,x2);
			if (!st.contains(x2)) {ok=0;break;}
			st.extract(x2);
			b.push_back(x2);
			x=x1;
		}
		
		if (ok) st.extract(x);
		else {
			for(auto e1 : b) st.insert(e1);
		}
		return ok;
	};
	
	vector<int> ans;
	for(int i=vec.size()-1;i>=0;i--) {
		while (check(vec[i])) ans.push_back(vec[i]);
	}
	cout<<ans.size()<<"\n";
	for(auto e1 : ans) cout<<e1<<" ";
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







