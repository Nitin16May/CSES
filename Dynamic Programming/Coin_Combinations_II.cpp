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
    ll n,k,mod=1e9+7;
    cin >> n >> k;
    vector<int> a(n);
    f(i,0,n-1)cin >> a[i];
    vector<vector<int>> dp(n,vector<int> (k+1,0));
    f(i,0,k)
    {
        dp[0][i]=1;
        i+=(a[0]-1);
    }
    f(i,1,n-1)
    {
        f(j,0,k)
        {
            dp[i][j]=dp[i-1][j];
            if(a[i]<=j)dp[i][j]=(dp[i][j]+dp[i][j-a[i]]);
        }
    }
    cout << dp[n-1][k];
}