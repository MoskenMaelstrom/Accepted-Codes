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
	vector<int> a(n),b(n);
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++) sum1^=a[i],sum2^=b[i];
	
	B base;
	for(int i=0;i<n;i++) {
		int x=a[i]^b[i];
		base.insert(x);
	}
	
	int ans=max(sum1,sum2);
	for(int i=60;i>=0;i--) {
		if (max(sum1^base.b1[i],sum2^base.b1[i]) < ans) {
			ans=max(sum1^base.b1[i],sum2^base.b1[i]);
			sum1^=base.b1[i];
			sum2^=base.b1[i];
		}
	}
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







