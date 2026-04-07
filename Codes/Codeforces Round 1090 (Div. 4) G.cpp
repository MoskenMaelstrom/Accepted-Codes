#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=676767677;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> b(n);
	vector vec(m+1,vector<int>(0));
	for(int i=0;i<n;i++) {
		cin>>b[i];
		vec[b[i]].push_back(i);
	}
	if (n == 1) {
		if (b[0] == 0) cout<<"1\n";
		else cout<<"0\n";
		return;
	}

	bool ok=1;
	if (b[0] != 0 and b[0] <= b[1]) ok=0;
	if (b[n-1] != 0 and b[n-2] >= b[n-1]) ok=0;
	for(int i=1;i<n-1;i++) {
		if (b[i] == 0) continue;
		if (b[i-1] >= b[i] and b[i] <= b[i+1]) ok=0;
	}
	if (!ok) {cout<<"0\n";return;}
	
	int pcnt=0;
	int cnt=vec[0].size();
	int ans=1;
	for(int i=1;i<=m;i++) {
		for(auto id : vec[i]) {
			if (id == 0) {
				if (b[id] == b[id+1]+1 and b[id+1] != 0) (ans*=cnt)%=p;
				else (ans*=cnt-pcnt)%=p;
			}
			else if (id == n-1) {
				if (b[id-1]+1 == b[id] and b[id-1] != 0) (ans*=cnt)%=p;
				else (ans*=cnt-pcnt)%=p;
			}
			else {
				if (b[id-1] == 0 or b[id+1] == 0) (ans*=cnt-pcnt)%=p;
				else if (b[id-1]+1 >= b[id] and b[id] <= b[id+1]+1) (ans*=cnt)%=p;
				else (ans*=cnt-pcnt)%=p;
			}
		}
		// cout<<ans<<endl;
		pcnt=cnt;
		cnt+=vec[i].size();
	}
	cout<<ans<<"\n";
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







