#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define test ll savingvariablestousethemafter;cin>>savingvariablestousethemafter;while(savingvariablestousethemafter--)
vector<int> a,ans(1000000,-1);
int n,flag=1;
int solve(int f)
{
    int lol,kam=INT_MAX,i,x;
    
    if(ans[f-1]!=-1)
    return ans[f-1];
    
    if(f<a[1])
    {
        if(f%a[0]!=0)
        {
            ans[f-1]=INT_MIN;
            return INT_MIN;
        }
        ans[f-1]=(f/a[0]);
        return (f/a[0]);
    }
    
    for(i=n-1;i>=0;i--)
    {
        if(a[i]>f)
        continue;
        x=solve(f-a[i]);
        if(x==INT_MIN)
            continue;
        lol=1+x;
        if(lol<kam)
        kam=lol;
    }
    if(kam==INT_MAX)
    kam=INT_MIN;
    ans[f-1]=kam;
    return ans[f-1];
}
int main()
{
    speed;
    int nn , x,c;
    cin >> nn >> x;
    n=nn;
    while(nn--)
    {
        cin >>c;
        ans[c-1]=1;
        a.push_back(c);
    }
    sort(a.begin(),a.end());
 
    int answer=solve(x);
    
    if(answer!=INT_MIN)
    cout << answer << endl;
    else
    cout << -1 << endl;
}