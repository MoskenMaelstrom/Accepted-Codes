// Problem: P1833 樱花
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1833
// Memory Limit: 128 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	string s1,s2;
	int n;
	cin>>s1>>s2>>n;
	int h1,h2,m1,m2;
	for(int i=0;i<s1.size();i++) {
		if (s1[i] == ':') {
			h1=stoll(s1.substr(0,i));
			m1=stoll(s1.substr(i+1,s1.size()-i-1));
		}
	}
	for(int i=0;i<s2.size();i++) {
		if (s2[i] == ':') {
			h2=stoll(s2.substr(0,i));
			m2=stoll(s2.substr(i+1,s2.size()-i-1));
		}
	}
	int t=h2*60+m2-(h1*60+m1);
	
	vector<array<int,2>> gra;
	for(int i=0;i<n;i++) {
		int cost,val,num;
		cin>>cost>>val>>num;
		
		if (num != 0) {
			for(int i=0;num-(1<<i) >= 0;i++) {
				int k=(1<<i);
				gra.push_back({cost*k,val*k});
				num-=k;
			}
			if (num != 0) gra.push_back({cost*num,val*num});
		}
		else {
			for(int i=0;i<=15;i++) {
				int k=(1<<i);
				gra.push_back({cost*k,val*k});
			}
		}
	}
	
	vector<int> dp(t+1);
	for(int i=0;i<gra.size();i++) {
		for(int j=t;j>=gra[i][0];j--) {
			dp[j]=max(dp[j],dp[j-gra[i][0]]+gra[i][1]);
		}
	}
	cout<<dp[t];
	
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









