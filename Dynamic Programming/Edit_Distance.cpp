#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
    string s,t;
    cin >> s >> t;
    ll lt=t.size();
    ll ls=s.size();
    vector<vector<ll>> dp(lt+1,vector<ll> (ls+1,0));
    for(ll i=1;i<=ls;i++)dp[0][i]=i;
    for(ll i=1;i<=lt;i++)dp[i][0]=i;
    for(ll i=1;i<=lt;i++)
    {
        for(ll j=1;j<=ls;j++)
        {
            ll a=dp[i-1][j]+1,b;b=a;
            if(t[i-1]==s[j-1])b=dp[i-1][j-1];
            ll c=1+dp[i-1][j-1];
            ll d=1+dp[i][j-1];
            dp[i][j]=min(min(a,d),min(b,c));
        }
    }
    cout << dp[lt][ls];
}