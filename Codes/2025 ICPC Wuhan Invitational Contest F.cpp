// Problem: F. Knapsack
// Contest: Codeforces - 2025 ICPC Wuhan Invitational Contest (The 3rd Universal Cup. Stage 37: Wuhan)
// URL: https://codeforces.com/gym/105901/problem/F
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int p=998244353;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) (res*=base)%=p;
		(base*=base)%=p;
	}
	return res;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	map<int,int,greater<int>> mp;
	for(int i=0;i<n;i++) {
		int a,b;
		cin>>a>>b;
		mp[b]+=a;
	}
	
	int rest=0,ans=0;
	int last=-1;
	for(auto [v,c] : mp) {
		if (rest > 0) {
			for(int i=last;i>v;i--) {
				if (rest > (int)1e15/2) {
					cout<<ans<<"\n";
					return;
				}
				rest*=2;
			}
		}
		
		if (rest >= c) rest-=c;
		else {
			c-=rest;
			int C=(c+m-1)/m;
			(ans+=Pow(2,v)*(C%p))%=p;
			rest=C*m-c;
		}
		last=v;
	}
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







