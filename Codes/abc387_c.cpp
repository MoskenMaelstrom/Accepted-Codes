// Problem: C - Snake Numbers
// Contest: AtCoder - AtCoder Beginner Contest 387
// URL: https://atcoder.jp/contests/abc387/tasks/abc387_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int Pow(int base, int exp) {
    int res = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base);
        }

        exp = exp >> 1;
        base = (base * base);
    }

    return res;
}

int get(int num) {
	int cnt=0;
	while (num != 0) {
		cnt++;
		num/=10;
	}
	return cnt;
}

int front(int num) {
	if (num == 0) return 0;
	int b=get(num);
	return num/Pow(10,b-1);
}

void solve()
{
	int l,r;
	cin>>l>>r;
	function<int(int,int,int,bool)> work=[&](int num,int f1,int len,bool free) {
		if (len == 0) return 0ll;
		int res=0;
		if (get(num) == len) {
			for(int i=1;i<f1;i++) {
				res+=work(num,i,len-1,1);
			}
			res+=work(num,f1,len-1,0);
			res+=work(Pow(10,get(num)-1)-1,9,len-1,0);
		}
		else {
			if (free) {
				res+=f1*max(1ll,work(num,f1,len-1,1));
			}
			else {
				int b=num/Pow(10,len-1)%10;
				res+=min(f1,b)*max(1ll,work(num,f1,len-1,1));
				if (b < f1) res+=work(num,f1,len-1,0);
				if (b < f1 and len == 1) res++;
			}
		}
		
		return res;
	};
	
	cout<<work(r,front(r),get(r),0)-work(l-1,front(l-1),get(l-1),0);
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









