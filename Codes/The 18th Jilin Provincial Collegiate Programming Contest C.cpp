// Problem: C. SSPPSPSP
// Contest: Codeforces - The 18th Jilin Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105922/problem/C
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	string s;
	cin>>s;
	
	int cur;
	if (s.back() == 'p') {
		cur=1;
		for(auto x : a) (cur*=x)%=p;
	}
	else {
		cur=0;
		for(auto x : a) (cur+=x)%=p;
	}
	
	for(int i=s.size()-2;i>=0;i--) {
		if (s[i] == 's') (cur*=n)%=p;
		else {
			int c=cur;
			for(int j=0;j<n-1;j++) (cur*=c)%=p;
		}
	}
	cout<<cur;
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







