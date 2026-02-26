// Problem: E. Mexification
// Contest: Codeforces - Codeforces Round 1047 (Div. 3)
// URL: https://codeforces.com/contest/2137/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: E. Mexification
// Contest: Codeforces - Codeforces Round 1047 (Div. 3)
// URL: https://codeforces.com/contest/2137/problem/E
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

int mex(vector<int>& arr) {
    set<int> numSet(arr.begin(), arr.end());
    int mex = 0;
    while (numSet.find(mex) != numSet.end()) {
        mex++;
    }
    return mex;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	vector<int> cnt(n+10);
	for(int i=0;i<n;i++) {cin>>a[i];cnt[a[i]]++;}
	
	if (k <= 10) {
		for(int i=0;i<k;i++) {
			vector<int> b(n);
			int M=mex(a);
			for(int j=0;j<n;j++) {
				if (cnt[a[j]] > 1) b[j]=M;
				else b[j]=min(a[j],M);
			}
			a=b;
			for(int j=0;j<n+10;j++) cnt[j]=0;
			for(int j=0;j<n;j++) cnt[a[j]]++;
		}
		int sum=0;
		for(int e1 : a) sum+=e1;
		cout<<sum<<endl;
	}
	else {
		for(int i=0;i<10;i++) {
			vector<int> b(n);
			int M=mex(a);
			for(int j=0;j<n;j++) {
				if (cnt[a[j]] > 1) b[j]=M;
				else b[j]=min(a[j],M);
			}
			a=b;
			for(int j=0;j<n+10;j++) cnt[j]=0;
			for(int j=0;j<n;j++) cnt[a[j]]++;
		}
		int sum1=0;
		int sum2=0;
		for(int e1 : a) sum1+=e1;
		
			vector<int> b(n);
			int M=mex(a);
			for(int j=0;j<n;j++) {
				if (cnt[a[j]] > 1) b[j]=M;
				else b[j]=min(a[j],M);
			}
			a=b;
		for(int e1 : a) sum2+=e1;
		
		if ((k-10)%2 == 1) cout<<sum2<<endl;
		else cout<<sum1<<endl;
	}
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









