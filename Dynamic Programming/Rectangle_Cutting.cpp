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
    ll n,m,lol;
    cin >> n >> m;
    dvec dp(n+1,vec(m+1,0));
    f(i,1,n)
    {
        f(j,1,m)
        {
            if(i==j)dp[i][j]=0;
            else
            {
                lol=LLONG_MAX;
                f(k,1,j-1)lol=min(dp[i][j-k]+dp[i][k]+1,lol);
                f(k,1,i-1)lol=min(dp[i-k][j]+dp[k][j]+1,lol);
                dp[i][j]=lol;
            }
        }
    }
    cout << dp[n][m];
}