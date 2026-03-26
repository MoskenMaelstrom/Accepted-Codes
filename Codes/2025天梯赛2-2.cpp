#include<bits/stdc++.h>
// #define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=1e6;
bool mark[3][2*N+1];
void solve()
{
	int n;
	cin>>n;
	vector<int> vec[3];
	for(int i=0;i<n;i++) {
		int x,y;
		cin>>x>>y;
		if (!mark[y][x+N]) vec[y].push_back(x);
		mark[y][x+N]=1;
	}
	
	int n0=vec[0].size();
	int n1=vec[1].size();
	int n2=vec[2].size();
	// for(auto x : vec[0]) cout<<x<<" ";
	// cout<<endl;
	// for(auto x : vec[1]) cout<<x<<" ";
	// cout<<endl;
	// for(auto x : vec[2]) cout<<x<<" ";
	// cout<<endl;
	
	vector<array<int,6>> ans;
	if (n0 >= n1 and n0 >= n2) {
		for(int i=0;i<n1;i++) {
			for(int j=0;j<n2;j++) {
				int x=vec[1][i]-(vec[2][j]-vec[1][i]);
				if (!mark[0][x+N]) continue;
				ans.push_back({x,0,vec[1][i],1,vec[2][j],2});
			}
		}
	}
	else if (n1 >= n0 and n1 >= n2){
		for(int i=0;i<n0;i++) {
			for(int j=0;j<n2;j++) {
				if ((vec[0][i]+vec[2][j])&1) continue;
				int x=vec[0][i]+vec[2][j]>>1;
				if (!mark[1][x+N]) continue;
				ans.push_back({vec[0][i],0,x,1,vec[2][j],2});
			}
		}
	}
	else {
		for(int i=0;i<n0;i++) {
			for(int j=0;j<n1;j++) {
				int x=vec[1][j]+(vec[1][j]-vec[0][i]);
				if (!mark[2][x+N]) continue;
				ans.push_back({vec[0][i],0,vec[1][j],1,x,2});
			}
		}
	}
	
	ranges::sort(ans,[&](array<int,6> X,array<int,6> Y) {
		if (X[2] != Y[2]) return X[2] < Y[2];
		else return X[0] < Y[0];
	});
	for(auto [x1,y1,x2,y2,x3,y3] : ans) cout<<"["<<x1<<", "<<y1<<"] ["<<x2<<", "<<y2<<"] ["<<x3<<", "<<y3<<"]"<<"\n";
	if (ans.size() == 0) cout<<"-1";
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







