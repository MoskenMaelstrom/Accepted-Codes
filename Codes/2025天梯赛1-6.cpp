#include<bits/stdc++.h>
#define int __int128
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int Pow(int base,int exp) {
	int res=1;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base;
		base*=base;
	}
	return res;
}

void solve()
{
	i64 n;
	cin>>n;
	i64 exp=0;
	i64 ed=0;
	for(int i=1;1+(1<<i)<=n and i<32;i++) {
		int sum=0;
		int len=0;
		for(int j=1;sum<n;j++) {
			sum+=Pow(j,i);
			len=j;
		}
		if (sum == n) {
			exp=i;
			ed=len;
		}
	}
	if (exp) {
		cout<<"1^"<<exp;
		for(i64 j=2;j<=ed;j++) cout<<"+"<<j<<"^"<<exp;
	}
	else cout<<"Impossible for "<<n<<".";
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







