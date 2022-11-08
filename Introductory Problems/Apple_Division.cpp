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
    ll TESTCASES=1,n,x;
    //cin>>TESTCASES;
    f(test,1,TESTCASES)
    {
        cin >> n;
        vec a(n);
        ll ans=LLONG_MAX;
        f(i,0,n-1)cin >> a[i];
        f(i,1,pow(2,n)-1)
        {
            ll s1=0,s2=0;
            f(j,0,n-1)
            {
                if((i>>j & 1)==1)s1+=a[j];
                else s2+=a[j];
            }
            ans=min(ans,abs(s1-s2));
        }
        cout << ans;
    }
}