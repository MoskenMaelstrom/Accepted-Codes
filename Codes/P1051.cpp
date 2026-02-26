// Problem: 
//     P1051 [NOIP2005 提高组] 谁拿了最多奖学金
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1051
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,s1,s2,sum=0,max=0,total=0,x;
    char a,b;
    string name,maxn;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>name>>s1>>s2>>a>>b>>x;
        if (s1 > 80 and x > 0) sum+=8000;
        if (s1 > 85 and s2 > 80) sum+=4000;
        if (s1 > 90) sum+=2000;
        if (s1 > 85 and b == 'Y') sum+=1000;
        if (s2 > 80 and a == 'Y') sum+=850;
        total+=sum;
        if(sum > max)
            maxn=name,max=sum;
        sum=0;
    }
    cout<<maxn<<endl<<max<<"\n"<<total;
    return 0;
}