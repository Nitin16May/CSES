#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define test ll savingvariablestousethemafter;cin>>savingvariablestousethemafter;while(savingvariablestousethemafter--)
vector<ll> ans(1000000,-1);
ll solve(ll n)
{
    ll sum=0;
    if(n<=6)
    return (ll)pow(2,n-1);
    else
    {
        for(int i=1;i<=6;i++)
        {
            if (ans[n-i-1]==(ll)-1)
            ans[n-i-1]=solve(n-i);
            sum=(sum+ans[n-i-1])%(1000000007);
        }
        return sum;
    }
}
int main()
{
    speed;
    ll n;
    cin >> n;
    cout << solve(n);
}