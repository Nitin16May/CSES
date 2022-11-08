#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define test ll savingvariablestousethemafter;cin>>savingvariablestousethemafter;while(savingvariablestousethemafter--)
 
int main()
{
    speed;
    ll n,x;
    cin >> n >> x;
    ll c[n];vector<ll> ans(1000001,0);
    ans[0]=0;
    for(ll i=0;i<n;i++)
    {cin >> c[i];ans[c[i]]=1;}
    for(ll i=0;i<=x;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i-c[j]>0)
            ans[i]=(ans[i]+ans[i-c[j]])%1000000007;
        }
    }
    cout << ans[x];
}