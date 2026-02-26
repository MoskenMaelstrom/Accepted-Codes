// Problem: 数据时间？
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95334/J
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
// #define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	set<string> st1,st2,st3;
	int n,y,t;
	cin>>n>>y>>t;
	while (n--) {
		string id;
		cin>>id;
		int a1,a2,a3,b1,b2,b3;
		scanf("%d-%d-%d %d:%d:%d",&a1,&a2,&a3,&b1,&b2,&b3);
		if (a1 == y and a2 == t) {
			if (b1 == 7 or b1 == 8 or b1 == 9 and b2 == 0 and b3 == 0) st1.insert(id);
			if (b1 == 18 or b1 == 19 or b1 == 20 and b2 == 0 and b3 == 0) st1.insert(id);
			if (b1 == 11 or b1 == 12 or b1 == 13 and b2 == 0 and b3 == 0) st2.insert(id);	
			if (b1 == 22 or b1 == 23 or b1 == 0 or b1 == 1 and b2 == 0 and b3 == 0) st3.insert(id);
		}
	}
	cout<<st1.size()<<" "<<st2.size()<<" "<<st3.size()<<endl;
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









