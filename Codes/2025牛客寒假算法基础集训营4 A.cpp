// Problem: Tokitsukaze and  Absolute Expectation
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95336/A
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int p=1e9+7;
int pow(int base, int exp, int mod) {
    int res = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return res;
}

int ny(int num) {
	return pow(num,p-2,p)%p;
}

int work1(int l1,int r1,int l2,int r2) {
	int a1=l2-l1,am=r2-l1,m=r2-l2+1;
	int sum1=(a1+am)*m%p*ny(2)%p;
	int n=r1-l1+1,sumn=(sum1-(n-1)*m%p+p)%p;
	return (sum1+sumn)*n%p*ny(2)%p;
}

int work2(int l,int r) {
	int n=r-l;
	return (n*(n+1)%p*(2*n+1)%p*ny(6)%p+(n+1)*n%p*ny(2)%p)%p;
}

void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	
	int fz=0,fm=1;
	for(int i=0;i<n;i++) {
		auto [l,r]=a[i];
		fm*=r-l+1;
		fm%=p;
	}
	// cout<<fm<<endl;
	for(int i=1;i<n;i++) {
		auto [l1,r1]=a[i-1];
		auto [l2,r2]=a[i];
		int d1=r1-l1+1,d2=r2-l2+1;
		
		if (l2<=l1 and r1 <= r2) {
			fz+=(work1(l2,l1-1,l1,r1)+work2(l1,r1)+work1(l1,r1,r1+1,r2))*(fm*ny(d1*d2%p)%p);
		}
		else if (l1<=l2 and r2<=r1) {
			fz+=(work1(l1,l2-1,l2,r2)+work2(l2,r2)+work1(l2,r2,r2+1,r1))*(fm*ny(d1*d2%p)%p);	
		}
		else if (l1<=r2 and r2<=r1) {
			fz+=(work1(l2,l1-1,l1,r1)+work2(l1,r2)+work1(l1,r2,r2+1,r1))*(fm*ny(d1*d2%p)%p);	
		}
		else if (l1<=l2 and l2<=r1) {
			fz+=(work1(l1,l2-1,l2,r2)+work2(l2,r1)+work1(l2,r1,r1+1,r2))*(fm*ny(d1*d2%p)%p);
		}
		else if (r2 < l1) {
			fz+=work1(l2,r2,l1,r1)*(fm*ny(d1*d2%p)%p);
		}
		else if (r1 < l2) {
			fz+=work1(l1,r1,l2,r2)*(fm*ny(d1*d2%p)%p);
		}
		fz%=p;
	}
	// cout<<"fz:"<<fz<<" fm:"<<fm<<endl;
	cout<<fz*ny(fm)%p<<endl;
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









