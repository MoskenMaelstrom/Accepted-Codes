// Problem: G. Rock-Paper-Scissors
// Contest: Codeforces - The 18th Jilin Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105922/problem/G
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int d;
	int n;
	cin>>n;
	int a1,a2,a3;
	int b1,b2,b3;
	cin>>a1>>a2>>a3;
	cin>>b1>>b2>>b3;
	int maxn=0,minn=0;
	int a11=a1,a22=a2,a33=a3;
	int b11=b1,b22=b2,b33=b3;
	
	maxn+=min(a1,b2)+min(a2,b3)+min(a3,b1);
	d=min(a1,b2),a1-=d,b2-=d;
	d=min(a2,b3),a2-=d,b3-=d;
	d=min(a3,b1),a3-=d,b1-=d;
	d=min(a1,b1),a1-=d,b1-=d;
	d=min(a2,b2),a2-=d,b2-=d;
	d=min(a3,b3),a3-=d,b3-=d;
	maxn-=max(a1,b3)+max(a2,b1)+max(a3,b2);
	
	
	a1=a11,a2=a22,a3=a33;
	b1=b11,b2=b22,b3=b33;
	minn-=min(a1,b3)+min(a2,b1)+min(a3,b2);
	d=min(a1,b3),a1-=d,b3-=d;
	d=min(a2,b1),a2-=d,b1-=d;
	d=min(a3,b2),a3-=d,b2-=d;
	d=min(a1,b1),a1-=d,b1-=d;
	d=min(a2,b2),a2-=d,b2-=d;
	d=min(a3,b3),a3-=d,b3-=d;
	minn+=max(a1,b2)+max(a2,b3)+max(a3,b1);
	cout<<maxn<<" "<<minn<<"\n";
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







