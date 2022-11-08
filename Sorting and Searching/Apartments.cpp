#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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
 
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,m,d;
    cin >> n >> m >> d;
    vec a(n),b(m);
    f(i,0,n-1)cin >> a[i];
    f(i,0,m-1)cin >> b[i];
    sort(all(a));sort(all(b));
    ll ans=0,ai=0,bi=0;
    while(ai<n && bi<m)
    {
        if(abs(a[ai]-b[bi])<=d){ans++;ai++;bi++;}
        else if(a[ai]<b[bi])ai++;
        else bi++;
    }
    cout << ans;
}