// Problem: C. Cost of a Bracket Sequence
// Contest: Codeforces - Educational Codeforces Round 191 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2233/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	auto calc=[&](string ss) {
		int res=0;
		vector<char> sta;
		for(int i=0;i<ss.size();i++) {
			if (!sta.empty() and sta.back() == '(' and ss[i] == ')') {
				sta.pop_back();
				res+=2;
			}	
			else sta.push_back(ss[i]);
		}
		return res;
	};
	int cnt=calc(s);
	vector<int> ans(n);
	
	for(int i=0;i<=k;i++) {
		vector<int> vec(n);
		int a1=i,a2=k-i;
		for(int j=0;j<n and a1;j++) {
			if (a1 and s[j] == '(') a1--,vec[j]=1;
		}
		for(int j=n-1;j>=0 and a2;j--) {
			if (a2 and s[j] == ')') a2--,vec[j]=1;
		}
		string ss;
		for(int j=0;j<n;j++) {
			if (!vec[j]) ss+=s[j];
		}
		int cur=calc(ss);
		if (cur < cnt) ans=vec,cnt=cur;
	}
	for(auto x : ans) cout<<x;
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







