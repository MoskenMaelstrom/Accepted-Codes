// Problem: E. Sponsor of Your Problems
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

//不带mod
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
void solve()
{
    int n1,n2;
    cin>>n1>>n2;
	int n3=n1;
	int n=0;
	while (n3 != 0) {
		n3/=10;
		n++;
	}
	
    vector<int> l(n),r(n);
    for(int i=0;i<n;i++) l[i]=n1/pow(10ll,i)%10;
    for(int i=0;i<n;i++) r[i]=n2/pow(10ll,i)%10;
    int ok=1;
    int cnt=0;
    for (int i=n-1;i>=0;i--) {
        if (l[i] == r[i])
            cnt++;
        else break;
    }
    int c1=0,c0=0;
    if (cnt == n or l[n-1-cnt]+1 < r[n-1-cnt]) {
        cout<<cnt*2<<endl;
        return;
    }
    int pos=n - 1 - cnt;
    for (int i=pos-1;i>=0;i--) {
        if (l[i] == 9) c0++;
        else break;
    }
    for (int i=pos-1;i>=0;i--) {
        if (r[i] == 0) c1++;
        else break;
    }
    cout<<cnt*2+1+min(c1,c0)<<endl;
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


















