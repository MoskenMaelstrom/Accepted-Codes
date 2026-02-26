// Problem: C. Serval and The Formula
// Contest: Codeforces - Codeforces Round 1011 (Div. 2)
// URL: https://codeforces.com/contest/2085/problem/C
// Memory Limit: 256 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

int N2P(int64_t num)
{
    if (num <= 0) return 1;
    num--;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    num |= num >> 32;
    return num + 1;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	int n1=N2P(n);
	int cha=n1-n;
	int m1=m+cha;
	if (n1+m1 == (n1^m1)) cout<<cha<<endl;
	else {
		m1=N2P(m);
		cha=m1-m;
		n1=n+cha;
		if (n1+m1 == (n1^m1)) cout<<cha<<endl;
		else cout<<-1<<endl;
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









