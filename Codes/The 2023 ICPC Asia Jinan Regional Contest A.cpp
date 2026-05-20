// Problem: A. Many Many Heads
// Contest: Codeforces - The 2023 ICPC Asia Jinan Regional Contest (The 2nd Universal Cup. Stage 17: Jinan)
// URL: https://codeforces.com/gym/104901/problem/A
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
	int cnt=0;
	for(int i=1;i<n;i++) {
		if ((s[i-1] == '[' or s[i-1] == ']') and (s[i] == '[' or s[i] == ']')) cnt++;
		if ((s[i-1] == '(' or s[i-1] == ')') and (s[i] == '(' or s[i] == ')')) cnt++;
	}
	if (cnt > 2) cout<<"No\n";
	else cout<<"Yes\n";
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







