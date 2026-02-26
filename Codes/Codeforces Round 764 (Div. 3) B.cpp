#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c;
	if (a > c) swap(a,c);
	//动第一个
	d=c-b;
	if (b-d > 0 and (b-d)%a == 0) {cout<<"YES\n";return;}
	//动第二个
	d=(c-a)/2;
	if (a+d > 0 and (a+d)%b == 0 and (c-a)%2 == 0) {cout<<"YES\n";return;}
	//动第三个
	d=b-a;
	if (b+d > 0 and (b+d)%c == 0) {cout<<"YES\n";return;}
	
	cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









