#include<bits/stdc++.h>
using namespace std;
int dp[1005]={0};
void init(int n)
{
    for(int i=0;i<n;i++)
        dp[i]=1;
}
int lic(int *ar,int e,int m)
{
    for(int i=1;i<=e;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(ar[j]>ar[i] || j==m)
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=e;i++)
       ans=max(dp[i],ans);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,m;
       cin>>n>>m;
       int peaks[1005];
       for(int i=0;i<n;i++)
        cin>>peaks[i];
        init(n);
        int a=lic(peaks,n-1,m);
        cout<<a<<endl;
    }
    return 0;
}
