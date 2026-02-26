// Problem: E - Trapezium
// Contest: AtCoder - AtCoder Beginner Contest 418
// URL: https://atcoder.jp/contests/abc418/tasks/abc418_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
// Problem: E - Trapezium
// Contest: AtCoder - AtCoder Beginner Contest 418
// URL: https://atcoder.jp/contests/abc418/tasks/abc418_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e9;
signed main() {
	ios::sync_with_stdio(0);cin.tie(nullptr);
	int n;
	cin>>n;
	vector<array<int,2>> a(n);	
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	
	unordered_map<int,int> cnt;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			auto [x1,y1]=a[i];
			auto [x2,y2]=a[j];
			int g=gcd(y1-y2,x1-x2);
			int mid=(x1+x2)*N+y1+y2;
			if (cnt.count(-(y1-y2)/g*N-(x1-x2)/g)) cnt[-(y1-y2)/g*N-(x1-x2)/g]++;
			else cnt[(y1-y2)/g*N+(x1-x2)/g]++;
			mp[mid]++;
		}
	}
	
	int ans=0;
	for(auto [k,c] : cnt) {
		ans+=(c-1)*c/2;
	}
	for(auto [mid,c] : mp) {
		ans-=(c-1)*c/2;
	}
	cout<<ans;
	return 0;
}