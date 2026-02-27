// Problem: F. Ranking Prediction
// Contest: Codeforces - The 2025 Jiangsu Collegiate Programming Contest, The 2025 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105945/problem/F
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,a,b,s;
	cin>>n>>a>>b>>s;
	vector<bool> ok(n);
	vector<int> time(n);
	vector<int> vec;
	int ans=0,cnt=0;
	for(int i=0;i<s;i++) {
		int t;
		char c;
		string res;
		cin>>t>>c>>res;
		int id=c-'A';
		if (ok[id]) continue;
		if (res == "rj") time[id]+=20;
		if (res == "ac") ans+=time[id]+t,ok[id]=1,cnt++;
		if (res == "pd") vec.push_back(time[id]+t),ok[id]=1;
	}
	ranges::sort(vec);
	auto check=[&]() -> bool {
		if (cnt > a or cnt == a and ans < b) return 1;
		return 0;
	};
	
	int res=0;
	for(auto T : vec) {
		if (check()) {cout<<res<<"\n";return;}
		res++;
		cnt++;
		ans+=T;
	}
	if (check()) cout<<res<<"\n";
	else cout<<"-1\n";
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







