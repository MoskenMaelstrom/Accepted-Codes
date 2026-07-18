// Problem: Show Hand
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133876/J
// Memory Limit: 2048 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
// #define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	vector mark(15,vector<bool>(4));
	
	vector<array<int,2>> a(5);
	for(int i=0;i<4;i++) {
		string s;
		cin>>s;
		if ('2' <= s[0] and s[0] <= '9') a[i][0]=s[0]-'0';
		else if (s[0] == 'T') a[i][0]=10;
		else if (s[0] == 'J') a[i][0]=11;
		else if (s[0] == 'Q') a[i][0]=12;
		else if (s[0] == 'K') a[i][0]=13;
		else if (s[0] == 'A') a[i][0]=14;
		
		if (s[1] == 'C') a[i][1]=0;
		else if (s[1] == 'D') a[i][1]=1;
		else if (s[1] == 'H') a[i][1]=2;
		else if (s[1] == 'S') a[i][1]=3;
	}
	vector<array<int,2>> b(5);
	for(int i=0;i<4;i++) {
		string s;
		cin>>s;
		if ('2' <= s[0] and s[0] <= '9') b[i][0]=s[0]-'0';
		else if (s[0] == 'T') b[i][0]=10;
		else if (s[0] == 'J') b[i][0]=11;
		else if (s[0] == 'Q') b[i][0]=12;
		else if (s[0] == 'K') b[i][0]=13;
		else if (s[0] == 'A') b[i][0]=14;
		
		if (s[1] == 'C') b[i][1]=0;
		else if (s[1] == 'D') b[i][1]=1;
		else if (s[1] == 'H') b[i][1]=2;
		else if (s[1] == 'S') b[i][1]=3;
	}
	
	for(int i=0;i<4;i++) mark[a[i][0]][a[i][1]]=1;
	for(int i=0;i<4;i++) mark[b[i][0]][b[i][1]]=1;
	// for(auto [k,c] : a) {
		// // cout<<k<<" "<<c<<"\n";
		// mark[k][c]=1;
	// }
	// for(auto [k,c] : b) {
		// // cout<<k<<" "<<c<<"\n";
		// mark[k][c]=1;
	// }

	// vector<int> aa(5);
	// int k1=0;
	// vector<int> bb(5);
	// int k2=0;
	auto work=[&](vector<int>& v,vector<array<int,2>> vec,int& k) -> void {
		k=0;
		ranges::sort(vec);
		bool th=1;
		for(int i=0;i<4;i++) {
			if (vec[i][1] != vec[i+1][1]) {th=0;break;}
		}
		bool sz=1;
		for(int i=0;i<4;i++) {
			if (vec[i][0]+1 != vec[i+1][0]) sz=0;
		}
		if (vec[0][0] == 2 and vec[1][0] == 3 and vec[2][0] == 4 and vec[3][0] == 5 and vec[4][0] == 14) sz=1;
		
		if (sz) k=max(k,5);
		if (th) {
			if (sz and vec[0][0] == 10) k=max(k,10);
			else if (sz) k=max(k,9);
			else k=max(k,6);
		}
		
		vector<int> tmp;
		unordered_map<int,int> mp;
		for(int i=0;i<5;i++) mp[vec[i][0]]++;
		for(auto [K,cnt] : mp) tmp.push_back(cnt);
		ranges::sort(tmp);
		if (tmp.back() == 4) k=max(k,8);
		else if (tmp.back() == 3 and tmp[tmp.size()-2] == 2) k=max(k,7);
		else if (tmp.back() == 3) k=max(k,4);
		else if (tmp.back() == 2 and tmp[tmp.size()-2] == 2) k=max(k,3);
		else if (tmp.back() == 2) k=max(k,2);
		else k=max(k,1);
		
		if (vec[0][0] == 2 and vec[1][0] == 3 and vec[2][0] == 4 and vec[3][0] == 5 and vec[4][0] == 14) {
			v={1,2,3,4,5};
		}
		else {
			v.clear();
			vector<array<int,2>> t;
			for(auto [K,cnt] : mp) t.push_back({K,cnt});
			ranges::sort(t,[](array<int,2> X,array<int,2> Y) {
				if (X[1] != Y[1]) return X[1] > Y[1];
				return X[0] > Y[0];
			});
			for(auto [K,cnt] : t) {
				while (cnt--) v.push_back(K);
			}
		}
		
	};
	// auto cmp=[&]() -> int {
		// if (k1 > k2) return 1;
		// if (k1 < k2) return -1;
// 		
		// if (aa > bb) return 1;
		// if (aa < bb) return -1;
		// return 0;
	// };
	
	vector<int> vec;
	for(int i=2;i<=14;i++) {
		for(int j=0;j<4;j++) {
			if (mark[i][j]) continue;
			vec.push_back((i-2)*4+j);
		}
	}
	vector<pair<int,vector<int>>> a1(52),b1(52);
	for(int id : vec) {
		int i=id/4+2;
		int j=id%4;
		a[4]={i,j};
		vector<int> va;
		int ka;
		work(va,a,ka);
		a1[id]={ka,va};
		
		b[4]={i,j};
		vector<int> vb;
		int kb;
		work(vb,b,kb);
		b1[id]={kb,vb};
	}
	
	int f=-1;
	for(int x : vec) {
		int ff=-1;
		for(auto y : vec) {
			if (x == y) continue;
			auto cmp=[&]() -> int {
				if (a1[y] > b1[x]) return 1;
				if (a1[y] < b1[x]) return -1;
				return 0;
			};
			ff=max(ff,cmp());
			if (ff == 1) break;
		}
		f=max(f,-ff);
		if (f == 1) break;
	}
	
	// for(int i=2;i<=14;i++) {
		// for(int j=0;j<4;j++) {
			// if (mark[i][j]) continue;
			// b[4]={i,j};
			// mark[i][j]=1;
			// work(bb,b,k2);
			// int ff=-1;
			// for(int ii=2;ii<=14;ii++) {
				// for(int jj=0;jj<4;jj++) {
					// if (mark[ii][jj]) continue;
					// a[4]={ii,jj};
					// mark[ii][jj]=1;
					// work(aa,a,k1);
					// ff=max(ff,cmp());
					// mark[ii][jj]=0;	
					// if (ff == 1) break;
				// }
				// if (ff == 1) break;
			// }
			// mark[i][j]=0;
			// f=max(f,-ff);
			// if (f == 1) break;
		// }
		// if (f == 1) break;
	// }
	
	if (f == 1) cout<<"GeiWoCaPiXie\n";
	else if (f == 0) cout<<"PaiMeiYouWenTi\n";
	else cout<<"WoYaoYanPai\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







