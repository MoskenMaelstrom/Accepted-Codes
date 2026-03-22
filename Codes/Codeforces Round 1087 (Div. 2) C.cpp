// Problem: C. Find the Zero
// Contest: Codeforces - Codeforces Round 1087 (Div. 2)
// URL: https://codeforces.com/contest/2209/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int query(int i,int j) {
	cout<<"? "<<i<<" "<<j<<endl;
	int res;
	cin>>res;
	return res;
}

void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=2*n-4;i+=2) {
		auto res=query(i,i+1);
		if (res) {cout<<"! "<<i<<endl;return;}
	}
	auto res=query(2*n-3,2*n-2);
	if (res) {cout<<"! "<<2*n-3<<endl;return;}
	res=query(2*n-2,2*n-1);
	if (res) {cout<<"! "<<2*n-2<<endl;return;}
	res=query(2*n-3,2*n-1);
	if (res) {cout<<"! "<<2*n-3<<endl;return;}
	cout<<"! "<<2*n<<endl;
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







