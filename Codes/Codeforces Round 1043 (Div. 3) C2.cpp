// Problem: C2. The Cunning Seller (hard version)
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/C2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

int pow(int base, int exp) {
    int res = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base);
        }

        exp = exp >> 1;
        base = (base * base);
    }

    return res;
}
int cost(int x) {
    return pow(3,x+1)+x*pow(3,x-1);
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> d;
	
	int temp=n;
	while (temp > 0) {
		d.push_back(temp%3);
		temp/=3;
	}
	
	int cnt=0;
	for(int i=0;i<d.size();i++) {
		if (d[i] != 0) {
			cnt+=d[i];
		}
	}
	
	if (k < cnt) {cout<<"-1\n";return;}
	int c=k-cnt;
	int N=d.size();
	for(int i=N-1;i>=0;i--) {
		if (c <= 1) break;
		if (c/2 >= d[i] and i != 0) {
			c-=d[i]*2;
			d[i-1]+=3*d[i];
			d[i]=0;
		}
		else if (i != 0 and c > 1) {
			d[i]-=c/2;
			d[i-1]+=c/2*3;
			c=0;
		}
	}
	
	int ans=0;
	for(int i=0;i<d.size();i++) {
		if (d[i] != 0) {
			ans+=cost(i)*d[i];
		}
	}
	cout<<ans<<'\n';
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









