#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int x,y;
	cin>>x>>y;
	bool ok=1;
	if ((x+y)%2 == 0 and x == 0) ok=0;
	if ((x+y)%2 == 1 and y == 0) ok=0;
	if (x > y) ok=0;
	if (!ok) {cout<<"No\n";return;}
	if (x+y == 1) {cout<<"Yes\n";return;}

	cout<<"Yes\n";
	if ((x+y)%2 == 0) {
		int p=1;
		for(int i=0;i<(x-1)*2;i++) {
			cout<<p<<" "<<p+1<<"\n";
			p+=1;
		}
		for(int i=p+1;i<=x+y;i++) {
			cout<<p<<" "<<i<<"\n";
		}
	}
	else {
		if (x == 0) {
			for(int i=2;i<=x+y;i++) {
				cout<<1<<" "<<i<<"\n";
			}
			return;
		}
		y--;
		int p=2;
		for(int i=0;i<(x-1)*2;i++) {
			cout<<p<<" "<<p+1<<"\n";
			p+=1;
		}
		for(int i=p+1;i<=x+y+1;i++) {
			cout<<p<<" "<<i<<"\n";
		}
		cout<<"1 2\n";
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







