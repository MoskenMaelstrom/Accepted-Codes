// Problem: D. Tung Tung Sahur
// Contest: Codeforces - Codeforces Round 1017 (Div. 4)
// URL: https://codeforces.com/contest/2094/problem/D
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
	string s1,s2;
	cin>>s1>>s2;
	vector<int> a1,a2;
	
	s1+=" ";
	s2+=" ";
	int n1=0,n2=0;
	int cnt=0;
	for(int i=0;i<s1.size();i++) {
		if (n1%2 == 0 and s1[i] == 'L') cnt++;
		else if (n1%2 == 1 and s1[i] == 'R') cnt++;
		else {
			a1.push_back(cnt);
			n1++;
			cnt=1;
		}
		
	}
	
	cnt=0;
	for(int i=0;i<s2.size();i++) {
		if (n2%2 == 0 and s2[i] == 'L') cnt++;
		else if (n2%2 == 1 and s2[i] == 'R') cnt++;
		else {
			a2.push_back(cnt);
			n2++;
			cnt=1;
		}
		
	}
	
	// for(auto e1 : a1) cout<<e1<<" ";cout<<endl;
	// for(auto e1 : a2) cout<<e1<<" ";cout<<endl;
	
	if (n1 != n2) cout<<"NO\n";
	else {
		for(int i=0;i<n1;i++) {
			if (a1[i] > a2[i] or a1[i]*2 < a2[i]) {cout<<"NO\n";return;}
		}
		cout<<"YES\n";
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









