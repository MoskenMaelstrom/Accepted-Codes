// Problem: C. DIY
// Contest: Codeforces - 2024-2025 ICPC, NERC, Southern and Volga Russian Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/problemset/problem/2038/C
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


struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

void solve()
{
	int n;
	cin>>n;
	unordered_map<int, int, custom_hash> mp;
	for(int i=0;i<n;i++) {
		int e1;
		cin>>e1;
		mp[e1]++;
	}
	
	multiset<int> st;
	for(auto [e1,e2] : mp) {
		if (e2 >= 2) st.insert(e1);
		if (e2 >= 4) st.insert(e1);
		if (e2 >= 6) st.insert(e1);
		if (e2 >= 8) st.insert(e1);
	}
	
	if (st.size() < 4) cout<<"NO\n";
	else {
		cout<<"YES\n";
		
		int x1=*st.begin();
		int y1=*(++st.begin());
		int x2=*(--(--st.end()));
		int y2=*(--st.end());
		cout<<x1<<" "<<y1<<" ";
		cout<<x2<<" "<<y1<<" ";
		cout<<x2<<" "<<y2<<" ";
		cout<<x1<<" "<<y2<<" ";
		cout<<endl;
	}
	
	
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









