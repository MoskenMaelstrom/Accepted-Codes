// Problem: Bitwise Maximization
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133877/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct B {
	vector<int> b1,b2;
    int cnt;
    bool zero;
    B() : b1(61,0),b2(61,0),cnt(0),zero(0) {}

    void insert(int x) {
        for (int i=60;i>=0;i--) {
            if (x>>i&1) {
                if (!b1[i]) {b1[i]=x;return;}
                x^=b1[i];
            }
        }
        zero=1;
    }

    void build() {
        cnt=0;
        for (int i=60;i>=0;i--)
            for (int j=i-1;j>=0;j--)
                if (b1[i]>>j&1) b1[i]^=b1[j];
        
        for (int i=0;i<=60;i++)
            if (b1[i]) b2[cnt++]=b1[i];
    }

    int kth(int k) {
        if (zero) k--;
        if (k == 0) return 0;
        if (k >= (1LL<<cnt)) return -1;
        
        int res=0;
        for (int i=0;i<cnt;i++)
            if (k>>i&1) res^=b2[i];
        return res;
    }
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int sum=0;
	for(int i=0;i<n;i++) sum^=a[i];
	B b;
	for(int i=0;i<n;i++) {
		b.insert(a[i]&(~sum));
	}
	b.build();
	cout<<sum+b.kth(1<<b.cnt)*2<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







