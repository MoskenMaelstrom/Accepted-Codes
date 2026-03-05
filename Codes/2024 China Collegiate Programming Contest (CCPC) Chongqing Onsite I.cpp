// Problem: I. 算术
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Chongqing Onsite
// URL: https://codeforces.com/gym/106030/problem/I
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int p=998244353;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) (res*=base)%=p;
		(base*=base)%=p;
	}
	return res;
}

void solve()
{
	vector<int> a(11);
	for(int i=1;i<=9;i++) cin>>a[i];
	int k=min(a[1],a[2]);
	a[1]-=k;
	a[2]-=k;
	a[3]+=k;
	
	a[3]+=a[1]/3;
	a[1]%=3;
	if (a[1] == 1) {
		int num=0;
		for(int i=2;i<=9;i++) {
			if (a[i] > 0) {num=i;break;}
		}
		a[num+1]++;
		a[num]--;
	}
	else if (a[1] == 2) {
		if (a[2] >= 2) {
			a[2]-=2;
			a[3]+=2;
		}
		else a[2]++;
	}
	
	int ans=1;
	for(int i=1;i<=10;i++) {
		// cout<<a[i]<<" ";
		(ans*=Pow(i,a[i]))%=p;
	}
	// cout<<endl;
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







