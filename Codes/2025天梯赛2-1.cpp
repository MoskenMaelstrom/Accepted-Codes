#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	vector<char> sta;
	vector<string> ans;
	for(int i=0;i<n;i++) {
		if (s[i] != ')') sta.push_back(s[i]);
		else {
			ans.push_back("");
			auto& cur=ans[ans.size()-1];
			while (sta.back() != '(') cur+=sta.back(),sta.pop_back();
			sta.pop_back();
		}
	}
	for(auto s1 : ans) {
		reverse(s1.begin(),s1.end());
		cout<<s1<<"\n";
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







