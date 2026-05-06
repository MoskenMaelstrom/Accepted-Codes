// Problem: J. Generate 01 String
// Contest: Codeforces - The 9th Hebei Collegiate Programming Contest
// URL: https://codeforces.com/gym/105909/problem/J
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	if (ranges::count(s,'0')*2 != n) {cout<<"-1";return;}
	
	vector<array<int,2>> sta;
	vector<int> vec(n,-1);
	for(int i=0;i<n;i++) {
		if (!sta.empty()) {
			auto [f,p]=sta.back();
			if (f == 1-(s[i]-'0')) {
				vec[p]=i;
				vec[i]=p;
				sta.pop_back();
			}
			else sta.push_back({s[i]-'0',i});
		}
		else sta.push_back({s[i]-'0',i});
	}
	
	// for(auto e1 : vec) cout<<e1<<" ";
	cout<<n/2<<"\n";
	int p=1;
	for(int i=0;i<n;i++) {
		if (vec[i] > i) {
			if (s[i] == '0') cout<<p<<" 1\n";
			else cout<<p<<" 2\n";
		}
		else p++;
	}
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







