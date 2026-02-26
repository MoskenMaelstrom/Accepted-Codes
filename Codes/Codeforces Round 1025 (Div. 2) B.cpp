// Problem: B. Slice to Survive
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int count(int n) {
	int cnt=0;
	while (n > 1) {
		cnt++;
		if (n%2 == 0) n/=2;
		else n=n/2+1;
	}
	return cnt;
}

void solve()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	int n1=x;
	int n2=n-x+1;
	int m1=y;
	int m2=m-y+1;
	
	int cnt=LLONG_MAX/100;
	cnt=min(cnt,count(n)+count(m1));
	cnt=min(cnt,count(n)+count(m2));
	cnt=min(cnt,count(n1)+count(m));
	cnt=min(cnt,count(n2)+count(m));
	cout<<cnt+1<<endl;
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









