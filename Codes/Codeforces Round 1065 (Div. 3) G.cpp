// Problem: G. Sakura Adachi and Optimal Sequences
// Contest: Codeforces - Codeforces Round 1065 (Div. 3)
// URL: https://codeforces.com/contest/2171/problem/G
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p=1e6+3;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp%2) res*=base;
		res%=p;
		base*=base;
		base%=p;
	}
	return res;
}

int ny(int num) {
	return Pow(num,p-2);
}

const int N=2e6;
int jc[N];

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
    
    int x=-1;
    int ans=0;
    for (int k=0;k<=20;k++) {
        bool ok=1;
        for(int i=0;i<n;i++) {
            if (a[i]*(1<<k) > b[i]) {
                ok=0;
                break;
            }
        }
        if (!ok) break; 

        int t=k;
        vector<int> vec(k+1,0);
        int cur=1;
        for(int i=0;i<n;i++) {
            int diff=b[i]-a[i]*(1<<k);
            int s0=diff>>k;
            vec[k]+=s0;
            t+=s0;
            cur*=ny(jc[s0]);
            cur%=p;	

            for(int j=1;j<=k;j++) {
                if ((diff>>(k-j))&1) {
                    vec[k-j]++;
                    t++;
                }
            }
        }

        for(int i=0;i<=k;i++) {
            if (vec[i] >= p) cur=0;
            else cur=(cur*jc[vec[i]])%p;
        }
        
        if (x == -1 or t < x) {
            x=t;
            ans=cur;
        } 
        else if (t == x) ans=(ans+cur)%p;
    }
    
    cout<<x<<" "<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	jc[0]=1;
	for(int i=1;i<N;i++) {
		jc[i]=jc[i-1]*i;
		jc[i]%=p;
	}
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}
