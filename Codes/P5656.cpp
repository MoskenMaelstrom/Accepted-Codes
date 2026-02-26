// Problem: 
//     P5656 【模板】二元一次不定方程 (exgcd)
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5656
// Memory Limit: 16 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int d,x,y,px,py;
void exgcd(int a,int b)
{
	if (b != 0) {
		exgcd(b,a%b);
		px=x;
		py=y;
		x=py;
		y=px-py*(a/b);
	} else {
		d=a;
		x=1;
		y=0;
	}
}

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if (c%(gcd(a,b)) != 0) {cout<<-1<<endl;return;}
	exgcd(a,b);
	x*=c/d;
	y*=c/d;
	//先算minx
	int t=ceil((1.0-x)/(b/d));
	int minx=x+t*b/d;
	int maxy=y-t*a/d;
	//再算maxx;
	t=ceil((1.0-y)/(a/d));
	int maxx=x-t*b/d;
	int miny=y+t*a/d;
	int num=(maxx-minx)/(b/d)+1;
	if (minx>0 and maxy>0) cout<<num<<" "<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
	else cout<<minx<<" "<<miny<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}




