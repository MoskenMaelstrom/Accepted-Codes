// Problem: A. 删除01串
// Contest: Codeforces - 2025年北京市大学生程序设计竞赛暨“小米杯”全国邀请赛
// URL: https://codeforces.com/gym/105851/problem/A
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if (n == 1) {cout<<s<<"\n";return;}
	if (s[0] != s[n-1]) {cout<<"empty\n";return;}
	
	if (s[0] == '0') {
		int ans=n;
		int cur=0;
		for(int i=0;i<n;i++) {
			if (s[i] == '1') ans=min(ans,cur),cur=0;
			else cur++;
		}
		ans=min(ans,cur);
		if (ans == 0) cout<<"empty\n";
		else cout<<string(ans,'0')<<"\n";
	}
	else {
		int ans=n;
		int cur=0;
		for(int i=0;i<n;i++) {
			if (s[i] == '0') ans=min(ans,cur),cur=0;
			else cur++;
		}	
		ans=min(ans,cur);
		if (ans == 0) cout<<"empty\n";
		else cout<<string(ans,'1')<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







