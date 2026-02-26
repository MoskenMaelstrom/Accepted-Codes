// Problem: U109895 [HDU4825]Xor Sum
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U109895
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

const int N=2e7;
int trie[N][2];
void solve()
{
	int n,m;
	cin>>n>>m;
	
	int cnt=1;
	auto insert=[&](int x) -> void {
		int p=1;//从1这个位置开始找
		for(int i=31;i>=0;i--) {
			int num=((x>>i)&1);
			if (trie[p][num] == 0) trie[p][num]=++cnt;
			p=trie[p][num];
		}
	};
	
	auto work=[&](int x) -> int {
		int p=1;
		int res=0;
		for(int i=31;i>=0;i--) {
			int num=((x>>i)&1);//取第i位
			if (trie[p][num^1] >= 1) {
				res+=((num^1)<<i);
				p=trie[p][num^1];
			}
			else res+=(num<<i),p=trie[p][num];
		}
		return res;
	};
	
	
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		insert(num);
	}
	
	for(int i=0;i<m;i++) {
		int num;
		cin>>num;
		cout<<work(num)<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









