#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
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
	int x,y;
	cin>>x>>y;
	int a0,a1,b;
	cin>>a0>>a1>>b;
	b=a0+a1;
	int p1=a0*Pow(b,p-2)%p;
	int p2=a1*Pow(b,p-2)%p;
	bool f=0;
	if (x > y) {
		swap(x,y);
		swap(p1,p2);
		f=1;
	}

	int g=gcd(x,y);
	int ans=0,cur=1;
	while (x != g or y != g) {
		if (x < y) {
			int t=(y-1)/x;
			y-=t*x;
			(cur*=Pow(p1,t))%=p;
		}
		else {
			int t=(x-1)/y;
			x-=t*y;
			(ans+=cur*(1-Pow(p2,t))%p)%=p;
			(cur*=Pow(p2,t))%=p;
		}
	}
	(ans+=cur*p1%p)%=p;
	if (f) cout<<(1-ans+p)%p<<"\n";
	else cout<<(ans+p)%p<<"\n";
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







