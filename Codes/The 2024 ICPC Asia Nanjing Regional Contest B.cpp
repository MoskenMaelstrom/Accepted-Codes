// Problem: B. Birthday Gift
// Contest: Codeforces - The 2024 ICPC Asia Nanjing Regional Contest (The 3rd Universal Cup. Stage 16: Nanjing)
// URL: https://codeforces.com/gym/105484/problem/B
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	vector<int> vec;
	for(int i=0;i<n;i++) {
		vec.push_back(s[i]-'0');
		while (vec.size() >= 2 and vec[vec.size()-1] == vec[vec.size()-2] and vec.back() != 2) {
			vec.pop_back(),vec.pop_back();
		}
	}
	// for(int i=0;i<vec.size();i++) cout<<vec[i];
	// cout<<"\n";
	n=vec.size();
	int c0=0,c1=0;
	int ans=n;
	for(int i=0;i<n;i++) {
		if (vec[i] == 0 and i%2 == 0) c0++;
		if (vec[i] == 0 and i%2 == 1) c1++;
	}
	ans-=min(c0,c1)*2;
	c0=c1=0;
	for(int i=0;i<n;i++) {
		if (vec[i] == 1 and i%2 == 0) c0++;
		if (vec[i] == 1 and i%2 == 1) c1++;
	}
	ans-=min(c0,c1)*2;
	int c2=ranges::count(vec,2);
	while (c2 > 0 and ans > 1) c2--,ans-=2;
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







