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
    ll TESTCASES=1,n;
    cin>>TESTCASES;
    f(test,1,TESTCASES)
    {
        cin >> n;
        ll x=9,s=1;
        while(true)
        {
            if(n>x*s){n-=(x*s);x*=10;s++;}
            else
            {
                x=x/9;
                if(n%s==0){n--;x+=(n/s);n=n%s;n++;}
                else{x+=(n/s);n=n%s;}
                cout << ((x/((ll)(pow(10,s-n))))%10ll) << endl;
                break;
            }
        }
    }
}