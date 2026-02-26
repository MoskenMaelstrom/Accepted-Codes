#include<bits/stdc++.h>
#define int long long
using namespace std;
int jc(int x)
{
	int num=1;
	for(int i=2;i<=x;i++) num*=i;
	return num;
}
void solve()
{
	cout<<"1 ";
	int n,d;
	cin>>n>>d;
	if (d == 3 or d == 9) cout<<"3 ";
	else if (n>=3) cout<<"3 ";
	else if ((d+d)%3 == 0) cout<<"3 ";
	
	if (d == 5) cout<<"5 ";
	
	if (d == 7) cout<<"7 ";
	else if (n >= 3) cout<<"7 ";
	else if ((d*10+d)%7 == 0) cout<<"7 ";
	
	if (d == 9) cout<<"9";
	else if (d == 3 and n >= 3) cout<<"9";
	else if (n >= 6) cout<<"9";
	else if (d*jc(n)%9 == 0) cout<<"9";
	cout<<"\n";
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