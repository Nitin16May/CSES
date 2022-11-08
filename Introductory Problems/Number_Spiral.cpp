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
//1 4 5 16 17 36
void solve(ll n,ll m)
{
    ll x=1+((max(n,m))-1)*(max(n,m));
    if(n>m)
    {
        if(n%2==1)cout << x-n+m << "\n";
        else cout << x+n-m << "\n";
    }
    else
    {
        if(m%2==0)cout << x-m+n << "\n";
        else cout << x+m-n << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    ll TESTCASES=1,n,m,x;
    cin>>TESTCASES;
    while(TESTCASES--)
    {
        cin >> n >> m;
        solve(n,m);
    }
}