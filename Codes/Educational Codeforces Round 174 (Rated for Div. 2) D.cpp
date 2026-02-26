// Problem: D. Palindrome Shuffle
// Contest: Codeforces - Educational Codeforces Round 174 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2069/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
#define int long long
using namespace std;

bool is_p(string s)
{
	string s1=s;
	ranges::reverse(s);
	return (s == s1);
}

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	if (is_p(s)) {cout<<"0\n";return;}
	
	vector<int> a(26),b(26);
	for(int i=0;i<n/2;i++) a[s[i]-'a']++,b[s[n-i-1]-'a']++;
	bool flag=1;
	for(int i=0;i<26;i++) {
		if (a[i] != b[i]) {flag=0;break;}
	}
	
	//#1
	if (flag) {
		vector<bool> a1(n/2,0);
		for(int i=0;i<n/2;i++) {
			if (s[i] == s[n-i-1]) a1[i]=1;
		}
		
		int l,r;
		for(int i=0;i<n/2;i++) {
			if (a1[i] == 0) {l=i;break;}
		}
		for(int i=n/2-1;i>=0;i--) {
			if (a1[i] == 0) {r=i;break;}
		}
		
		cout<<r-l+1<<endl;
	}
	
	
	//#2
	else {
		int mark=0;
		for(int i=0;i<n;i++) {
			if (s[i] != s[n-1-i]) {mark=i;break;}
		}
		s=s.substr(mark,n-mark*2);
		n=s.size();
		int ans;
		
		vector<int> A(26),a2(26);
		for(int i=0;i<n;i++) A[s[i]-'a']++;
		a2[s[n-1]-'a']++;
		int pos;
		for(int i=n-2;i>=0;i--) {
			a2[s[i]-'a']++;
			bool f1=1;
			for(int j=0;j<26;j++) {
				if (a2[j] > A[j]/2) f1=0,pos=i;
			}
			if (!f1) {ans=pos+1;break;}
		}
		
		a2.assign(26,0);
		ranges::reverse(s);
		a2[s[n-1]-'a']++;
		for(int i=n-2;i>=0;i--) {
			a2[s[i]-'a']++;
			bool f1=1;
			for(int j=0;j<26;j++) {
				if (a2[j] > A[j]/2) f1=0,pos=i;
			}
			if (!f1) {ans=min(ans,pos+1);break;}
		}
		cout<<ans<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









