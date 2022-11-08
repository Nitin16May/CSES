#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define test ll savingvariablestousethemafter;cin>>savingvariablestousethemafter;while(savingvariablestousethemafter--)
 
int main()
{
    speed;
    int n,i,j,f;
    cin >> n;
    vector<string> c(n); vector<vector<int>> a(n,vector<int>(n, 0));
    for(i=0;i<n;i++)
    cin >> c[i];
    f=1;
    for(i=n-1;i>=0;i--)
    {
        if(c[i][n-1]=='*')
        {a[i][n-1]=-1;f=0;}
        if(f==1)
        a[i][n-1]=1;
    }
    for(j=n-2;j>=0;j--)
    {
        for(i=n-1;i>=0;i--) 
        {
            if(c[i][j]=='*')
            {a[i][j]=-1;continue;}
            if(i+1<n)
            {
                if(a[i+1][j]!=-1)
                a[i][j]=(a[i][j]+a[i+1][j])%(1000000007);
            }
            if(j+1<n)
            {
                if(a[i][j+1]!=-1)
                a[i][j]=(a[i][j]+a[i][j+1])%(1000000007);
            }
        }
    }
    cout << max(0,a[0][0]);
}