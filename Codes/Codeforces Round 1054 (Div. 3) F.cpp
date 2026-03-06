// Problem: F. Nezuko in the Clearing
// Contest: Codeforces - Codeforces Round 1054 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2149/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int hp,d;
	cin>>hp>>d;
	int ans=0;
	if (hp == 1) hp++,ans++;
	int lo=1,hi=d,res=-1;//块数
	while (lo <= hi) {
		int mid=lo+hi>>1;
		int c=(d+mid-1)/mid;//长度
		int last=d-(mid-1)*c;//最后c-last个-1
		bool ok=1;
		int sum1=(1+c)*c/2;
		int sum2=(c-1)*c/2;
		if (sum1 >= hp) ok=0;
		if (hp-sum1*(mid-c+last)-sum2*(c-last)+mid-1 <= 0) ok=0;
		
		if (ok) hi=mid-1,res=mid;
		else lo=mid+1;
	}
	ans+=d+res-1;
	cout<<ans<<"\n";
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







