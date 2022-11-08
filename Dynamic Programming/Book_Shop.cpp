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
    ll n,w;
    cin >> n >> w;
    vector<vector<int>> dp(n,vector<int> (w+1,0));
    vector<int> weight(n),value(n);
    f(i,0,n-1)cin >> weight[i];
    f(i,0,n-1)cin >> value[i];
    for(int i=weight[0];i<=w;i++)dp[0][i]=value[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(weight[i]<=j)dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout << dp[n-1][w];
}