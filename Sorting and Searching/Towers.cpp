#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(ll i = a; i <= b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define llceil(a,b) a/b
#define llfloor(a,b) (a+b-1)/b
#define vec vector<ll>
#define dvec vector<vector<ll>>
//////*************Nitin1605***************//////
ll n,x,s;
vec a;
ll FirstTrue() 
{
    ll lo=0,hi=s-1;
    hi++;
    while (lo < hi) 
    {
        ll mid=lo+(hi-lo)/2;
        if(x<a[mid])hi=mid;
        else lo=mid+1;
    }
    return lo;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    cin >> n;s=0;
    f(i,1,n)
    {
        cin >> x;
        ll p=FirstTrue();
        if(p==s){a.pb(x);s++;}
        else a[p]=x;
    }
    cout << s;
}