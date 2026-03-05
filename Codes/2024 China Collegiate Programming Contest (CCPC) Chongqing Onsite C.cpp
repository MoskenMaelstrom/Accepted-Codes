// Problem: C. 连方
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Chongqing Onsite
// URL: https://codeforces.com/gym/106030/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	if (s1 == string(n,'#') and s2 == string(n,'#')) {
		cout<<"Yes\n";
		for(int i=0;i<7;i++) cout<<string(n,'#')<<"\n";
		return;
	}
	if (s1 == string(n,'#') or s2 == string(n,'#')) {cout<<"No\n";return;}
	
	vector<string> a(7);
	a[0]=s1;
	a[6]=s2;
	
	a[1]=string(n,'.');
	for(int i=0;i<n;i++) {
		a[1][i]=a[0][i] == '#' ? '.' : '#';
	}
	a[5]=string(n,'.');
	for(int i=0;i<n;i++) {
		a[5][i]=a[6][i] == '#' ? '.' : '#';
	}
	
	if (a[0] != "."+string(n-1,'#')) a[1][0]='.';
	if (a[6] != "."+string(n-1,'#')) a[5][0]='.';
	a[2]=string(n,'.');
	a[3]=string(n,'.');
	a[4]=string(n,'.');
	a[3][0]='#';
	
	if (a[1][1] == '.') {
		for(int i=1;a[1][i] == '.';i++) {
			a[2][i]='#';
		}
	}
	else a[2][0]='#';
	
	if (a[5][1] == '.') {
		for(int i=1;a[5][i] == '.';i++) {
			a[4][i]='#';
		}
	}
	else a[4][0]='#';
	
	cout<<"Yes\n";
	for(auto s : a) cout<<s<<"\n";
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







