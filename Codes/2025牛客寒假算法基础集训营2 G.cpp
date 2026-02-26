// Problem: 一起铸最好的剑！
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95334/G
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
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

void solve()
{
	int n,t;
	cin>>n>>t;
	if (t == 1) {cout<<"1\n";return;}
	if (t >= n) {cout<<"1\n";return;}
	int pt=t,k=t,cnt=1;
	while (t < n) {
		pt=t;
		t*=k;
		cnt++;
	}
	if (abs(t-n) >= abs(pt-n)) cout<<cnt-1<<endl;
	else cout<<cnt<<endl;
	
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









