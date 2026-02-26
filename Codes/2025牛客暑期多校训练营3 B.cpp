// Problem: Bitwise Puzzle
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108300/B
// Memory Limit: 1024 MB
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
	int a,b,c;
	vector<int> ans;
	cin>>a>>b>>c;
	if (a == b and b == c) {cout<<"0\n\n";return;}
	if (a == b and b == 0) {cout<<"-1\n";return;}

	auto work=[&](int num) {
		if (num == 1) a*=2;
		if (num == 2) b/=2;
		if (num == 3) a^=b;
		if (num == 4) b^=a;
		ans.push_back(num);
	};
	
	if (__lg(b) > __lg(a)) work(3);
	else if (__lg(b) < __lg(a)) work(4);
	
	if (c > a) {
		int cnt=1;
		while (1) {
			if ((fw != ((c>>(__lg(c)-cnt+1))&1)) work(3);
			cnt++;
			if (b == 1) break;
			work(2);
		}
		
		while (a != c) {
			work(1);
			if (((c>>(__lg(c)-cnt+1))&1) != 0) work(3);
			cnt++;
		}
		work(2);
		work(4);
	}
	else {
		int lena=__lg(a)+1;
		int cnt=1;
		while (b != 0) {
			// cout<<":"<<a<<" "<<b<<" "<<c<<endl;
			if (((a>>(lena-cnt))&1) != ((c>>(lena-cnt))&1)) work(3);
			work(2);
			cnt++;
		}
		work(4);
	}
	cout<<ans.size()<<'\n';
	for(auto e1 : ans) {
		cout<<e1<<' ';
	}
	cout<<'\n';
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









