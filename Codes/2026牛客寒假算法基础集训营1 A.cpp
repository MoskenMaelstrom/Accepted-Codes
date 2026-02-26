// Problem: A+B Problem
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/A
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=998244353;
const int N=1e6;
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

vector<int> vec[10]= {
	{1,2,3,5,6,7},{3,6},{1,3,4,5,7},{1,3,4,6,7},{2,3,4,6},
	{1,2,4,6,7},{1,2,4,5,6,7},{1,3,6},{1,2,3,4,5,6,7},{1,2,3,4,6,7}
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a(8);
	for(int i=1;i<=7;i++) {
		cin>>a[i];
		a[i]=a[i]*inv[100]%p;
	}
	
	vector<int> P(10);
	auto get=[&](int num) -> int {
		int res=1;
		for(int i=0;i<4;i++) {
			res=(res*P[num%10])%p;
			num/=10;x
		}
		return res;
	};
	
	for (int i=0;i<=9;i++) {
        int res=1;
        for (int j=1;j<=7;j++) {
            bool ok=0;
            for (int e1 : vec[i]) {
            	if (e1 == j) ok=1;
            }
            res=(res*(ok ? a[j] : (1-a[j]+p)%p))%p;
        }
        P[i]=res;
    }
    
	int ans=0;
	for (int i=0;i<=n;i++) {
        ans+=get(i)*get(n-i)%p;
        ans%=p;
    }
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	inv[1]=1;
	for(int i=2;i<=N;i++) inv[i]=p-inv[p%i]*(p/i)%p;
	
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







