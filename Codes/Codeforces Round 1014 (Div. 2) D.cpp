// Problem: D. Mishkin Energizer
// Contest: Codeforces - Codeforces Round 1014 (Div. 2)
// URL: https://codeforces.com/contest/2092/problem/D
// Memory Limit: 256 MB
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
	string s;
	cin>>s;
	if (ranges::count(s,s[0]) == n) {cout<< -1 <<endl;return;}
	
	
	vector<int> ans;
	auto ins=[&](char c) -> bool {
		for(int i=0;i<s.size()-1;i++) {
			if (s[i] != s[i+1] and s[i] != c and s[i+1] != c) {
				s.insert(i+1,1,c);
				ans.push_back(i+1);
				// cout<<s<<endl;
				return 1;	
			}
		}
		return 0;
	};

	int cnt=0;
	while (1) {
		int n1=ranges::count(s,'L');
		int n2=ranges::count(s,'I');
		int n3=ranges::count(s,'T');
		if (n1 == n2 and n2 == n3) break;
		
		char c;
		cnt++;
		vector<int> a;
		a.push_back(n1);a.push_back(n2);a.push_back(n3);ranges::sort(a);
		if (a[0] == n1) c='L';
		else if (a[0] == n2) c='I';
		else if (a[0] == n3) c='T';	
		
		if (ins(c)) continue;
		
		
		if (a[1] == n1 and c != 'L') c='L';
		else if (a[1] == n2 and c != 'I') c='I';
		else if (a[1] == n3 and c != 'T') c='T';
		ins(c);
	}
	
	cout << cnt << endl;
	for(auto e1 : ans) cout << e1 << endl;
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









