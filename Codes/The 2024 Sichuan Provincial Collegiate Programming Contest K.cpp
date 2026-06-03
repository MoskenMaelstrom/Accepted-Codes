// Problem: K. Element Reaction
// Contest: Codeforces - The 2024 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105222/problem/K
// Memory Limit: 256 MB
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
	int m,n;
	cin>>m>>n;
	vector a(m,vector<int>(m));
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	
	string s;
	cin>>s;
	vector<int> v(n);
	for(int i=0;i<n;i++) v[i]=s[i]-'a';
	
	vector<int> f(1<<m);
	vector<int> next(m,-1);
	int p=0;
	for(int i=n-1;i>=0;i--) {
		int need=0;
		int x=v[i];
		int y;
		for(int j=0;j<m;j++) {
			y=next[j];
			if (next[j] == -1) {p=j;break;}
			f[need]+=a[x][y];
			f[need|(1<<x)]-=a[x][y];
			f[need|(1<<y)]-=a[x][y];
			f[need|(1<<x)|(1<<y)]+=a[x][y];
			need|=(1<<y);
			if (x == y) {p=j;break;}
		}
		next.erase(next.begin()+p);
		next.insert(next.begin(),x);
	}
	
	for(int j=0;j<m;j++) {
		for(int i=0;i<1<<m;i++) {
			if ((i>>j)&1) f[i]+=f[i^(1<<j)];
		}
	}
	
	for(int i=0;i<1<<m;i++) cout<<f[i]<<" ";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







