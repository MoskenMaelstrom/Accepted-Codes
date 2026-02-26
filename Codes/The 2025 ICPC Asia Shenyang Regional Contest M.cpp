#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	vector<int> a(8);
	vector<int> b(8);
	
	for(int i=0;i<8;i++) {
		cin>>a[i]>>b[i];
	}
	vector<int> vec(8);
	ranges::iota(vec,0);
	
	auto work = [&]()
    {
        vector<double> p(8,1);
        for (int k=0;k<3;k++) {
            int len=1<<k;
            vector<double> tmp(8);
            for (int i=0;i<8;i++) {
                int st=(i/(len*2))*len*2;
                int l,r;
                if (st+len>i) l=st+len,r=st+len*2;
                else l=st,r=st+len;
                
                double res=0;
                for (int j=l;j<r;j++) {
                    int powi,powj;
                    if (i < j) powi=a[vec[i]],powj=b[vec[j]];
                    else powi=b[vec[i]],powj=a[vec[j]];
                    res+=p[j]*(double)powi/(powi+powj);
                }
                tmp[i]=p[i]*res;
            }
            p=tmp;
        }
        return p[ranges::find(vec,0)-vec.begin()];
    };
	
	double ans=0;
	do {
		ans=max(ans,work());
	} while (next_permutation(vec.begin(),vec.end()));
	cout<<fixed<<setprecision(15)<<ans;
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







