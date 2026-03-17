// Problem: E. Sum of Digits (and Again)
// Contest: Codeforces - Educational Codeforces Round 188 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2204/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int get(int n) {
	int sum=0;
	while (n) {
		sum+=n%10;
		n/=10;
	}
	return sum;
}

void solve()
{
	string s;
	cin>>s;
	if (s.size() == 1) {cout<<s<<"\n";return;}
	vector<int> cnt(10);
	int sum=0;
	for(auto c : s) {
		cnt[c-'0']++;
		sum+=c-'0';
	}
	
	int t=max(1ll,sum-100);
	for(int i=t;i<=sum;i++) {
		auto ncnt=cnt;
		bool ok=1;
		string cur;
		int x=i;
		while (1) {
			string s1=to_string(x);
			cur+=s1;
			for(auto c : s1) {
				ncnt[c-'0']--;
				if (ncnt[c-'0'] < 0) {ok=0;break;}
			}
			if (!ok) break;
			if (x <= 9) break;
			x=get(x);
		}
		
		int nsum=i;
		for(int j=0;j<10;j++) nsum-=j*ncnt[j];
		if (!ok or nsum != 0) continue;
		
		string ans;
		for(int j=1;j<10;j++) {
			if (ncnt[j]) {
				ans+=to_string(j);
				ncnt[j]--;
				break;
			}
		}
		
		for(int j=0;j<10;j++) {
			while (ncnt[j]) {
				ans+=to_string(j);
				ncnt[j]--;
			}
		}
		
		ans+=cur;
		cout<<ans<<"\n";
		return;
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







