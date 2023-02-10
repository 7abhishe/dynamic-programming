#include<bits/stdc++.h>
using namespace std;
int longest_subseq(const string& x,const string& y)
{
    int m=x.size();
    int n=y.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 ||j==0)
            {
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string x,y;
    cin>>x>>y;
    cout<<"longest subsequence\t"<<longest_subseq(x,y);
    return 0;
}