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
    char ch;dvec cb(8,vec (8,0));
    f(i,1,8)
    {
        f(j,1,8)
        {
            cin >> ch;
            if(ch=='*')cb[i-1][j-1]=1;
        }
    }
    string s="12345678";ll ans=0;
    do
    {
        vec d1(16,0),d2(16,0);
        f(i,0,7)d1[i+(s[i]-'1')]++;
        f(i,0,7)d2[i-(s[i]-'1')+7]++;
        bool flag=true;
        f(i,0,15)if(d1[i]>1 || d2[i]>1)flag=false;
        f(i,0,7)if(cb[i][s[i]-'1']==1)flag=false;
        if(flag)ans++;
    }while(next_permutation(all(s)));
    
    cout << ans << endl;
}