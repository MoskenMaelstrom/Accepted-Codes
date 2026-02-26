// Problem: D. Palindrome Flipping
// Contest: Codeforces - Codeforces Round 1067 (Div. 2)
// URL: https://codeforces.com/contest/2158/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void work(string s,vector<array<int,2>>& ans) {
	function<void(string,int)> sol=[&](string s1,int l) {
		if (s1 == "0000") return;
		else if (s1 == "0001") ans.push_back({l,l+2}),sol("1111",l);
		else if (s1 == "0010") ans.push_back({l,l+1}),sol("1110",l);
		else if (s1 == "0100") ans.push_back({l+2,l+3}),sol("0111",l);
		else if (s1 == "1000") ans.push_back({l+1,l+3}),sol("1111",l);
		else if (s1 == "0011") ans.push_back({l+2,l+3}),sol("0000",l);
		else if (s1 == "0101") ans.push_back({l+1,l+3}),sol("0010",l);
		else if (s1 == "1001") ans.push_back({l+1,l+2}),sol("1111",l);
		else if (s1 == "0110") ans.push_back({l+1,l+2}),sol("0000",l);
		else if (s1 == "1010") ans.push_back({l,l+2}),sol("0100",l);
		else if (s1 == "1100") ans.push_back({l,l+1}),sol("0000",l);
		else if (s1 == "0111") ans.push_back({l+1,l+3}),sol("0000",l);
		else if (s1 == "1011") ans.push_back({l+2,l+3}),sol("1000",l);
		else if (s1 == "1101") ans.push_back({l,l+1}),sol("0001",l);
		else if (s1 == "1110") ans.push_back({l,l+2}),sol("0000",l);
		else if (s1 == "1111") ans.push_back({l,l+3}),sol("0000",l);
	};	
	
	int n=s.size();
	for(int i=3;i<n;i+=4) {
		sol(s.substr(i-3,4),i-3);
		fill(s.begin()+i-3,s.begin()+i+1,'0');
	}
	sol(s.substr(n-4,4),n-4);
};

void solve()
{
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	
	vector<array<int,2>> ans1,ans2;
	work(a,ans1);
	work(b,ans2);
	ranges::reverse(ans2);
	cout<<ans1.size()+ans2.size()<<"\n";
	for(auto [e1,e2] : ans1) cout<<e1+1<<" "<<e2+1<<"\n";
	for(auto [e1,e2] : ans2) cout<<e1+1<<" "<<e2+1<<"\n";
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







