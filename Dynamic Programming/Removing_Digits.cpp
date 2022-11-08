#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define test ll savingvariablestousethemafter;cin>>savingvariablestousethemafter;while(savingvariablestousethemafter--)
 
int main()
{
    speed;
    ll n,md,i;vector<int> ans(1000000,0);
    cin >> n;
    for(i=1;i<=9;i++)
    ans[i-1]=1;
    for(i=10;i<=n;i++)
    {
        md=max(i%10,max((i/10)%10,max((i/100)%10,max((i/1000)%10,max((i/10000)%10,max((i/100000)%10,max((i/1000000)%10,max((i/10000000)%10,max((i/100000000)%10,(i/1000000000)%10)))))))));
        ans[i-1]=ans[i-md-1]+1;
    }
    cout << ans[n-1];
}