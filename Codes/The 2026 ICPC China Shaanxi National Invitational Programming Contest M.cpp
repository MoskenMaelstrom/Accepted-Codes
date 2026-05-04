#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	cout<<10*n-2<<"\n";
	for(int i=0;i<n;i++) cout<<"RDLD";
	for(int i=0;i<n-1;i++) cout<<"URRD";
	for(int i=0;i<n;i++) cout<<"L";
	cout<<"DL";
	for(int i=0;i<n;i++) cout<<"D";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







