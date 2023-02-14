#include <bits/stdc++.h>
using namespace std;
long long int dyck(int n)
{
    int ans=1;
    for(int i=0;i<n;i++)
    {
        ans=ans*(2*n-i);
        ans=ans/(i+1);
    }
    return ans/(n+1);
}
int main()
{
    
    
    //in this case 2ncn/(i+1) were being used in the above condition total no of way   to 
    //the given path
    int n;
    cin>>n;
   
    cout<<dyck(n)<<endl;
    return 0;
}