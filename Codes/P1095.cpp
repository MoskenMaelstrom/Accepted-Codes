// Problem: P1095 [NOIP 2007 普及组] 守望者的逃离
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1095
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int m,s,t;
	cin>>m>>s>>t;
	int T=t,S=s;
	while (t > 0) {
		t--;
		
		if (m >= 10) m-=10,s-=60;	//1s走60m
		else if (m >= 6 and s > 17) { //2s走60m
			if (t >= 1) m-=6,t--,s-=60;
			else s-=17; 
		}
		else if (m >= 2 and s > 34) { //3s走60m
			if (t >= 2) m-=2,t-=2,s-=60;
			else s-=17;
		}
		else if (m >= 0 and s > 102) {  //7s走120m
			if (t >= 6) t-=6,s-=120;
			else s-=17;
		}
		else s-=17;
		
		if (s <= 0) {cout<<"Yes\n"<<T-t;return;}
	}
	cout<<"No\n"<<S-s;
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









