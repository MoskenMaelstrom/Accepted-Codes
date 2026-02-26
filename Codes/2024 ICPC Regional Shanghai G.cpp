#include<bits/stdc++.h>
#define int long long
using namespace std;

int Ceil(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and !((n1 < 0)^(n2 < 0))) x++;
    return x;
}

int Floor(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and ((n1 < 0)^(n2 < 0))) x--;
    return x;
}

const int inf=2e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	multiset<int> c;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		c.insert(num);
	}
	
	function<bool(int)> check=[&](int y) {
		multiset<int> st=c;
		vector<array<int,2>> seg;
		int cnt=0;
		for(int i=0;i<n;i++) {
			int A=a[i],B=b[i];
			if (A == 0) cnt+=(B>=y);
			else if (A > 0) {
				int l=Ceil(y-B,A);
				seg.push_back({l,inf});
			}
			else {
				int r=Floor(y-B,A);
				seg.push_back({-inf,r});
			}
		}
		ranges::sort(seg);
		for(auto [l,r] : seg) {
			auto it=st.lower_bound(l);
			if (it == st.end()) continue;
			int num=*it;
			if (num <= r) {
				cnt++;
				st.erase(it);
			}
		}
		if (cnt >= (n+1)/2) return 1;
		else return 0;
	};
	
	int lo=-inf,hi=inf,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) lo=mid+1,res=mid;
		else hi=mid-1;
	}
	cout<<res<<"\n";
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







