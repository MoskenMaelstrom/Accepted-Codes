// Problem: E. Empty Triangle
// Contest: Codeforces - Codeforces Round 1009 (Div. 3)
// URL: https://mirror.codeforces.com/contest/2074/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int num;
	queue<array<int,3>> q;
	q.push({1,2,3});
	while (!q.empty()) {
		auto [n1,n2,n3]=q.front();
		q.pop();	
		cout<<"? "<<n1<<" "<<n2<<" "<<n3<<endl;
		cin>>num;
		if (num == 0) {cout<<"! "<<n1<<" "<<n2<<" "<<n3<<endl;return;}
		int R=rand()%3;
		if (R == 0) q.push({num,n1,n2});
		else if (R == 1) q.push({num,n2,n3});
		else if (R == 2) q.push({num,n1,n3});
	}
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









