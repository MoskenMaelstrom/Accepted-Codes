// Problem: M. V-Diagram
// Contest: Codeforces - The 2023 ICPC Asia Hangzhou Regional Contest (The 2nd Universal Cup. Stage 22: Hangzhou)
// URL: https://codeforces.com/gym/104976/problem/M
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> vec;
	for(int i=1;i<n-1;i++) {
		if (a[i-1] > a[i] and a[i] < a[i+1]) vec.push_back(i);
	}
	
	double ans=0;
	for(auto p : vec) {
		int l=p-1,r=p+1;
		int sum=a[l]+a[l+1]+a[l+2];
		int sum1,sum2,sum3;
		int c1,c2,c3;
		sum1=sum2=sum3=sum;
		c1=c2=c3=3;
		while (1) {
			bool ok=0;
			if (l > 0 and a[l-1] > a[l]) {
				l--;
				sum1+=a[l];
				c1++;
				sum3+=a[l];
				c3++;
				ok=1;
			}
			
			if (r < n-1 and a[r] < a[r+1]) {
				r++;
				sum2+=a[r];
				c2++;
				sum3+=a[r];
				c3++;
				ok=1;
			}
			if (!ok) break;
		}
		ans=max({ans,(double)sum/3,(double)sum1/c1,(double)sum2/c2,(double)sum3/c3});
	}
	
	cout<<fixed<<setprecision(15)<<ans<<"\n";
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







