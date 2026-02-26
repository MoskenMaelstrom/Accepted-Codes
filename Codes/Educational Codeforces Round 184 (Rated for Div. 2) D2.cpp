// Problem: D2. Removal of a Sequence (Hard Version)
// Contest: Codeforces - Educational Codeforces Round 184 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2169/problem/D2
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int Ceil(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and !((n1 < 0)^(n2 < 0))) x++;
    return x;
}

int Floor(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and ((n1 < 0)^(n2 < 0))) x--;
    return x;
}

const int inf=1e12;
void solve()
{
	int x,y,k;
	cin>>x>>y>>k;
	if (y == 1) {
		cout<<"-1\n";
	}
	else {
		int p=k-1;
		while (x > 0) {
			int r=p/(y-1);
			if (r == 0) break;
			int a=(y-1-p%(y-1)+r-1)/r;
			a=min(a,x);
			if (r > (inf-(1+p))/a) {cout<<"-1\n";return;}
			p+=a*r;
			x-=a;
		}
		cout<<p+1<<endl;
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






