// Problem: E. Do You Love Your Hero and His Two-Hit Multi-Target Attacks?
// Contest: Codeforces - Codeforces Round 1006 (Div. 3)
// URL: https://codeforces.com/contest/2072/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int k;
	cin>>k;
	if (k == 0) {cout<<0<<endl;return;}
	int n1=1;
	while (n1*(n1-1)/2 <= k) {
		n1++;
	} 
	n1--;//n1个点解决n1*(n1-1)对
	k-=n1*(n1-1)/2;
	
	
	int n2=1;
	while (n2*(n2-1)/2 <= k) {
		n2++;
	} 
	n2--;
	k-=n2*(n2-1)/2;
	
	
	int n3=1;
	while (n3*(n3-1)/2 <= k) {
		n3++;
	} 
	n3--;
	int n4=k-n3*(n3-1)/2+1;
	
	vector<array<int,2>> a;
	
	int x=-1,y=-1;
	while (n1--) {
		a.push_back({x,y});
		x-=3;
	}
	
	x=-2,y=-2;
	while (n2--) {
		a.push_back({x,y});
		x-=3;
	}
	
	x=-3,y=-3;
	while (n3--) {
		a.push_back({x,y});
		x-=3;
	}
	
	x=0,y=0;
	while (n4--) {
		a.push_back({x,y});
		if (x == y) y++;
		else x++;
	}
	
	
	cout<<a.size()<<endl;
	for(auto [e1,e2] : a) cout<<e1<<" "<<e2<<endl;
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









