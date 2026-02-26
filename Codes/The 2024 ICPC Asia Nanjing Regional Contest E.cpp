// Problem: E. Left Shifting 3
// Contest: Codeforces - The 2024 ICPC Asia Nanjing Regional Contest (The 3rd Universal Cup. Stage 16: Nanjing)
// URL: https://codeforces.com/gym/105484/problem/E
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	if (s.size() < 7) {cout<<"0\n";return;}
	k=min({k,6ll,n});
	for(int i=0;i<k;i++) {
		s+=s[i];
	}
	
	int cnt=0;
	for(int i=0;i<s.size()-6;i++) {
		string s1=s.substr(i,7);
		if (s1 == "nanjing") cnt++;
	}
	cout<<cnt<<"\n";
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







