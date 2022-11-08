#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(ll i = a; i <= b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define llceil(a,b) ceil(((double)a)/((double)b))
#define llfloor(a,b) floor(((double)a)/((double)b))
#define vec vector<ll>
#define dvec vector<vector<ll>>
//////*************Nitin1605***************//////

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    ll n,m,mod=1e9+7;
    cin >> n >> m;
    dvec dp(n+1,vec (m+2,0));
    vec a(n);
    f(i,0,n-1)cin >> a[i];
    if(a[0]==0)
    {
        f(i,1,m)dp[1][i]=1;
    }
    else dp[1][a[0]]=1;
    f(i,2,n)
    {
        if(a[i-1]==0)f(j,1,m)dp[i][j]=(((dp[i-1][j-1]+dp[i-1][j])%mod)+dp[i-1][j+1])%mod;
        else dp[i][a[i-1]]=(((dp[i-1][a[i-1]-1]+dp[i-1][a[i-1]])%mod)+dp[i-1][a[i-1]+1])%mod;
    }
    ll ans=0;
    f(i,1,m)ans=(ans+dp[n][i])%mod;
    cout << ans;
}