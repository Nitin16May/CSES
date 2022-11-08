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
    ll n,sum=0;
    cin >> n;
    vector<ll> a(n);
    dvec dp(n,vec (n,0));

    f(i,0,n-1){cin >> a[i];dp[i][i]=a[i];sum+=a[i];}
    fr(i,n-2,0)f(j,i+1,n-1)dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
    cout << (sum+dp[0][n-1])/2;
}