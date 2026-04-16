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
	string _;
	getline(cin,_);
	map<string,multiset<string>> mp;
	for(int i=0;i<n;i++) {
		string res;
		string s;
		getline(cin,s);
		string s1=s;
		s=" "+s;
		for(int j=0;j<s.size();j++) {
			if (j == s.size()-1 and s[j] == ' ') continue;
			if (s[j] == ' ' and 'a' <= s[j+1] and s[j+1] <= 'z') res+=s[j+1];
		}
		mp[res].insert(s1);
	}
	
	int m;
	cin>>m;
	getline(cin,_);
	for(int i=0;i<m;i++) {
		string res;
		string s;
		getline(cin,s);
		string s1=s;
		s=" "+s;
		for(int j=0;j<s.size();j++) {
			if (j == s.size()-1 and s[j] == ' ') continue;
			if (s[j] == ' ' and 'a' <= s[j+1] and s[j+1] <= 'z') res+=s[j+1];
		}
		
		if (mp.count(res) == 0) {
			cout<<s1<<"\n";
		}
		else if (mp[res].size() == 1) {
			cout<<*mp[res].begin()<<"\n";
		}
		else {
			bool ok=1;
			for(auto ss : mp[res]) {
				if (ok) {cout<<ss;ok=0;}
				else cout<<"|"<<ss;
			}
			cout<<"\n";
		}
	}
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







