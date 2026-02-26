// Problem: Equal
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108300/E
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int N = 5e6;
vector<vector<pair<int, int>>> zyz(N);
void cal() {
    vector<int> spf(N, 0);
    for (int i = 2; i < N; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (long long j = (long long)i * i; j < N; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    
    zyz[1] = {};
    
    for (int num = 2; num < N; ++num) {
        if (spf[num] == num) {
            zyz[num].emplace_back(num, 1);
        } else {
            int temp = num;
            int p = spf[num];
            zyz[num] = zyz[num / p];
            bool found = false;
            for (auto &[prime, cnt] : zyz[num]) {
                if (prime == p) {
                    cnt++;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                zyz[num].emplace_back(p, 1);
            }
        }
    }
}

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	if (n%2 == 1) {cout<<"YES\n";return;}
	if (n == 2) {
		if (a[0] == a[1]) {cout<<"YES\n";return;}
		else {cout<<"NO\n";return;}
	}
	
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++) {
		for(auto [e1,e2] : zyz[a[i]]) {
			mp[e1]+=e2;
		}
	}
	
	for(auto [e1,e2] : mp) {
		if (e2%2 == 1) {cout<<"NO\n";return;}
	}
	
	cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cal();
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









