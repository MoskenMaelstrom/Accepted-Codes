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
	set<string> st;
	string s;
	while (1) {
		int c=getchar();
		if (isalpha(c)) {
			if (isupper(c)) c=c-'A'+'a';
			s.push_back(c);
		}
		else {
			if (s.size() > 0) {
				st.insert(s);
				s.clear();
			}
			if (c=='\n') break;
		}
	}
	int n;
	cin>>n;
	while (n--) {
		string s1;
		cin>>s1;
		st.erase(s1);
	}
	cout<<st.size();
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









