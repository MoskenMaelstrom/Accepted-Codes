// Problem: A. 题目背景是 GPT 给的
// Contest: Codeforces - 第十三届重庆市大学生程序设计竞赛
// URL: https://codeforces.com/gym/105887/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
// #define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt=0;
	while (1) {
		bool ok=1;
		for(int i=1;i<n;i++) {
			if (a[i] != a[i-1]) ok=0;
		}
		if (ok) {cout<<cnt<<"\n";return;}
		auto b=a;
		for(int i=0;i<n;i++) {
			a[i]=b[(cnt+i+1)%n]|b[i];
		}
		cnt++;
	}
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







