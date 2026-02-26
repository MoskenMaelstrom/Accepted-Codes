// Problem: F. Puzzle
// Contest: Codeforces - Educational Codeforces Round 179 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2111/problem/F
// Memory Limit: 512 MB
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
using namespace std;

void solve()
{
	int p,s;
	cin>>p>>s;
	int g=gcd(p,s);
	p/=g;
	s/=g;
	
	if (p%2 == 1) p+=p,s+=s;
	int p1=p,s1=s;
	
	int l,r,a,b;
	auto check=[&]() {
		l=p/2-1;
		if (p/2%2 == 0) a=p/4,b=a;
		else a=p/4,b=a+1;
		r=a*b;
		if (l <= s and s <= r) return 1;
		else return 0;
	};
	
	while (s <= 5e4) {
		if (check()) break;
		else p+=p1,s+=s1;
	}
	
	if (l <= s and s <= r) {
		vector vec(a,vector<bool>(b));
		for(int i=0;i<a;i++) vec[i][0]=1;
		for(int j=0;j<b;j++) vec[0][j]=1;
		int cnt=a+b-1;
		for(int i=0;i<a;i++) {
			for(int j=0;j<b;j++) {
				if (vec[i][j] == 0) vec[i][j]=1,cnt++;
				if (cnt == s) break;
			}
			if (cnt == s) break;
		}
		// for(int i=0;i<a;i++) {
			// for(int j=0;j<b;j++) {
				// cout<<vec[i][j]<<" \n"[j == b-1];
			// }
		// }
		
		cout<<cnt<<"\n";
		for(int i=0;i<a;i++) {
			for(int j=0;j<b;j++) {
				if (vec[i][j] == 1) {
					cout<<i+1<<" "<<j+1<<"\n";
				}
			}
		}
	}
	else cout<<"-1\n";
	
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




