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
    //cin>>TESTCASES;
    f(test,1,TESTCASES)
    {
        string s;int ans=0;
        cin >> s;
        n=s.size();
        vec a(26,0);
        f(i,0,n-1)a[s[i]-'A']++;
        f(i,0,25)if(a[i]%2==1)ans++;
        if(ans<2)
        {
            ans=-1;
            f(i,0,25)
            {
                f(j,1,a[i]/2)cout << ((char)('A'+i));
                if(a[i]%2==1)ans=i;
            }
            if(ans!=-1)cout << ((char)('A'+ans));
            fr(i,25,0)
            {
                f(j,1,a[i]/2)cout << ((char)('A'+i));
            }
        }
        else cout << "NO SOLUTION" << endl;
    }
}