// Problem: D. 有限小数
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Chongqing Onsite
// URL: https://codeforces.com/gym/106030/problem/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

// 求出 ax+by=gcd(a,b)的一组特解(x,y)
int exgcd(int a,int b,int &x,int &y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}

// 求解 ax ≡ b (mod p)
int work(int a,int b,int p) {
    int x,y;
    int d=exgcd(a,p,x,y);
    if (b % d != 0) return -1; 
    int mod=p/d;//通解周期
    x=x%mod*((b/d)%mod)%mod;
    return (x+mod)%mod;
}

void solve()
{
	int a,b;
	cin>>a>>b;
	int w=b;
	while (w%2 == 0) w/=2;
	while (w%5 == 0) w/=5;
	b/=w;
	
	int ans=1e18;
	int d=-1;
	for(int i=1;i*w<=1e9;i*=5) {
		for(int j=i;j*w<=1e9;j*=2) {
			int B=-a*j;
			int c=work(b,B,w);
			if (c != -1 and c < ans) {
				ans=c;
				d=j*w;
			}
		}
	}
	cout<<ans<<" "<<d<<"\n";
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







