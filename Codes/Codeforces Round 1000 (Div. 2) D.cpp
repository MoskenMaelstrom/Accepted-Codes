// Problem: D. Game With Triangles
// Contest: Codeforces - Codeforces Round 1000 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2063/D
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

vector<int> ap,bp;
int f(int k,int x) {
	return ap[x]+bp[k-x];
}


int ts(int k,int L,int R){
    if (L > R) return 0;
    while (R-L > 3) {
        int mid1=L+(R-L)/3;
        int mid2=R-(R-L)/3;
        if (f(k,mid1) < f(k,mid2)) {
            L=mid1+1;
        }
        else {
            R=mid2-1;
        } 
    }
    int ans = 0;
    for (int i=L;i<=R;i++){
        ans=max(ans,f(k,i));
    }
    return ans;
}


void solve()
{
	ap.assign(1,0);
	bp.assign(1,0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(auto &e1 : a) cin>>e1;
	for(auto &e1 : b) cin>>e1;
	ranges::sort(a);
	ranges::sort(b);
	
	for(int i=0;i<n/2;i++) {
		ap.push_back(a[n-1-i]-a[i]);
	}
	for(int i=0;i<m/2;i++) {
		bp.push_back(b[m-1-i]-b[i]);
	}
	for(int i=1;i<ap.size();i++) ap[i]+=ap[i-1];
	for(int i=1;i<bp.size();i++) bp[i]+=bp[i-1];
	
	int kmax=min({n,m,(n+m)/3});
	cout<<kmax<<endl;
	
	//L代表a数组最少可以取2的个数
	for(int k=1;k<=kmax;k++) {
        int L = max({0ll, 2*k - m});
        int R = min({k, n - k});
		cout<<ts(k,L,R)<<" ";	
	}
	cout<<endl;
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









