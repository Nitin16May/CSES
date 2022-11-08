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
string DecToBin(ll n)
{return bitset<17>(n).to_string();}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll TESTCASES=1,n;
    //cin>>TESTCASES;
    f(test,1,TESTCASES)
    {
        cin >> n;
        f(lol,0,pow(2,n)-1)
        {
            string s=DecToBin(lol),ans="00000000000000000";
            f(i,1,16)
            {
                if(s[i-1]==s[i])ans[i]='0';
                else ans[i]='1';
            }
            f(i,16-n+1,16)cout << ans[i];cout << endl;
        }
    }
}