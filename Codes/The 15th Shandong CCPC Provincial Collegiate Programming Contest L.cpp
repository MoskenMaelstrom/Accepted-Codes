// Problem: L. Stella
// Contest: Codeforces - The 15th Shandong CCPC Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105930/problem/L
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	string s1,s2;
	cin>>s1>>s2;
	char a1=s1[0];
	char a2=s1[1];
	char b1=s2[0];
	char b2=s2[1];
	
	map<char,int> mp;
	mp['O']=9;
	mp['B']=8;
	mp['A']=7;
	mp['F']=6;
	mp['G']=5;
	mp['K']=4;
	mp['M']=3;
	
	if (mp[a1] < mp[b1] or mp[a1] == mp[b1] and a2 > b2) cout<<"cooler\n";
	else if (mp[a1] == mp[b1] and a2 == b2) cout<<"same\n";
	else cout<<"hotter\n";
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







