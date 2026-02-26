// Problem: D - 183184
// Contest: AtCoder - AtCoder Beginner Contest 428
// URL: https://atcoder.jp/contests/abc428/tasks/abc428_d
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

int Pow(int base, int exp) {
    int res = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base);
        }

        exp = exp >> 1;
        base = (base * base);
    }

    return res;
}

void solve()
{
	int a,b;
	cin>>a>>b;
	int dl=log10(a+1)+1;
	int dr=log10(a+b)+1;
	int ans=0;
	for(int d=dl;d<=dr;d++) {
		int l=max(a*Pow(10,dl)+a+1,a*Pow(10,d)+Pow(10,d-1));
		int r=min(a*Pow(10,dr)+a+b,a*Pow(10,d)+Pow(10,d)-1);
		int l1=sqrt(l-1);
		int r1=sqrt(r);
		ans+=r1-l1;
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








