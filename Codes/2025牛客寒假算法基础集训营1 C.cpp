// Problem: 兢兢业业之移
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/C
// Memory Limit: 512 MB
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

void solve()
{
	int n;
	cin>>n;
	vector<string> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector<array<int,4>> ans;
	auto work=[&](int x1,int y1,int x2,int y2) {
		swap(a[x1][y1],a[x2][y2]);
		ans.push_back({x1+1,y1+1,x2+1,y2+1});
	};
	
	auto move=[&](int i,int j,int x,int y) {
		if (j > y) {
			while (i > x) {work(i,j,i-1,j);i--;}
			while (i < x) {work(i,j,i+1,j);i++;}
			while (j > y) {work(i,j,i,j-1);j--;}
			while (j < y) {work(i,j,i,j+1);j++;}
		}
		else {
			while (j > y) {work(i,j,i,j-1);j--;}
			while (j < y) {work(i,j,i,j+1);j++;}
			while (i > x) {work(i,j,i-1,j);i--;}
			while (i < x) {work(i,j,i+1,j);i++;}
		}
	};
	
	int x=0,y=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			while (a[i][j] == '1') {
				move(i,j,x,y);
				a[x][y]='2';
				y++;
				if (y == n/2) x++,y=0;
			}
		}
	}
	
	cout<<ans.size()<<endl;
	for(auto [x1,y1,x2,y2] : ans) {
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
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









