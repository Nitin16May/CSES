#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    ll n,sum=0,ans=0;
    cin >> n;
    vec a(n);
    f(i,0,n-1)
    {
        cin >> a[i];
        sum+=a[i];
    }
    dvec dp(n+1, vec(sum+1,0));
    f(i,0,n)dp[i][0]=1;
    f(i,1,n)
    {
        f(j,1,sum)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=a[i-1])dp[i][j]=max(dp[i][j],dp[i-1][j-a[i-1]]);
        }
    }
    f(i,1,sum)if(dp[n][i]==1)ans++;cout << ans << endl;
    f(i,1,sum)if(dp[n][i]==1)cout << i << " ";
}