// Problem: D. Zhily and Barknights
// Contest: Codeforces - Codeforces Round 1097 (Div. 2,  Based on Zhili Cup 2026)
// URL: https://codeforces.com/contest/2224/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
const int N=1e6;
int jc[N+1];
int inv[N+1];

int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

int Inv(int num) {
	return Pow(num,p-2);
}

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	vector<array<int,2>> vec;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (i == j) continue;
			vec.push_back({b[j],b[i]});
		}
	}
	ranges::sort(vec,[&](array<int,2> X,array<int,2> Y) {
		return X[0]*Y[1] < Y[0]*X[1];
	});
	
	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			array<int,2> A={a[i],a[j]};
			int c=ranges::lower_bound(vec,A,[&](array<int,2> X,array<int,2> Y) {
				return X[0]*Y[1] < Y[0]*X[1];
			})-vec.begin();
			(ans+=c)%=p;
		}
	}
	cout<<ans*Inv(n*(n-1)%p)%p<<"\n";
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







