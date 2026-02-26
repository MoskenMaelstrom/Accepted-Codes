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

int p=998244353;
void solve()
{
	int n,sum=0;
	cin>>n;
	vector<int> a;
	while (n--) {
		string s;
		cin>>s;
		if (s == "Push") {
			int k;
			cin>>k;
			a.push_back(k);
			sum+=k;
			sum%=p;
		}
		else if (s == "Pop") {
			int k=*(--a.end());
			a.pop_back();
			sum-=k;
			sum=(sum+p)%p;
		}
		else {
			if (a.size() < 2e5) {
				a.insert(a.end(),a.begin(),a.end());
			}
			sum+=sum;
			sum%=p;
		}
		
		cout<<sum<<endl;
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









