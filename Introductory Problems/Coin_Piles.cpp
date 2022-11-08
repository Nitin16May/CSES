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
    ll TESTCASES=1,a,b,c;
    cin>>TESTCASES;
    f(test,1,TESTCASES)
    {
        cin >> a >> b;
        if(a<b)swap(a,b);
        c=min((a-b),b);
        a=a-2*c;b=b-c;
        c=(min(a,b)/3)*3;
        a=a-c;b=b-c;
        if((a==1 && b==2) || (a==2 && b==1) || (a==0 && b==0))yes;
        else no;
    }
}