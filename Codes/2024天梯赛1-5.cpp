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
	vector<string> vec(n);
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		vec[i]=s;
	}
	int k;
	cin>>k;
	
	string _;
	getline(cin,_);
	
	string s;
	getline(cin,s);
	
	string ans;
	int cnt=0;
	for(int i=0;i<s.size();) {
		bool ok;
		int len=1;
		for(auto& cur : vec) {
			ok=1;
			int m=cur.size();
			if (i+m > s.size()) {ok=0;continue;}
			for(int j=0;j<m;j++) {
				if (cur[j] != s[j+i]) {ok=0;break;}
			}
			if (ok) {len=m;break;}
		}
		if (ok) {
			cnt++;
			ans+="<censored>";
		}
		else ans+=s[i];
		i+=len;
	}
	
	if (cnt < k) cout<<ans;
	else cout<<cnt<<"\nHe Xie Ni Quan Jia!";
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







