// Problem: E. God's String on This Wonderful World
// Contest: Codeforces - 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105911/problem/E
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: E. God's String on This Wonderful World
// Contest: Codeforces - 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105911/problem/E
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

struct Hash {
    size_t operator()(const std::vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            seed ^= hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

unordered_map<vector<int>,int,Hash> mp;

const int N=3e5;
struct Q {
    int l,r,id,bl;
    bool operator<(const Q &q) const {
        if (bl != q.bl) return bl < q.bl;
        return (bl & 1) ? (r < q.r) : (r > q.r);
    }
};

void solve()
{
	int n,k,m;
	cin>>n>>k>>m;
	string s;
	cin>>s;
	s=" "+s;
	vector<int> cnt(N+1);
	int ans=0,id=0;
    vector<int> res(m);
    vector<Q> que(m);
	
	vector<int> q1(26);
	// map<vector<int>,int> mp;
	if (!mp.count(q1)) mp[q1]=++id;
	vector<int> vec(n+1);
	vec[0]=mp[q1];
	for(int i=1;i<=n;i++) {
		(q1[s[i]-'a']+=1)%=k;
		if (!mp.count(q1)) mp[q1]=++id;
		vec[i]=mp[q1];
	}

    int B=max(1ll,(int)(n / sqrt(m)));
    for (int i=0;i < m;i++) {
        cin>>que[i].l>>que[i].r;
        que[i].l--;
        que[i].id=i;
        que[i].bl=que[i].l/B;
    }
    sort(que.begin(),que.end());
	
	auto add=[&](int x) {
		ans+=cnt[vec[x]];
		cnt[vec[x]]++;
	};
	
	auto del=[&](int x) {
		cnt[vec[x]]--;
		ans-=cnt[vec[x]];
	};
	
    int l=1,r=0;
    for (auto &q : que) {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) del(l++);
        while (r > q.r) del(r--);
        res[q.id]=ans;
    }
    
    for(auto e1 : res) cout<<e1<<"\n";
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







