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
    ll n;
    cin >> n;
    if(n%4==0)
    {
        yes;
        cout << n/2 << endl;
        f(i,1,n/4)cout << i << " " << n-i+1 << " ";cout << endl;
        cout << n/2 << endl;
        f(i,n/4+1,n/4+n/2)cout << i << " ";cout << endl;
    }
    else if ((n+1)%4==0)
    {
        yes;
        cout << n/2 << endl;
        f(i,1,n/4)cout << i << " " << n-i << " ";cout << n << endl;
        cout << n/2+1 << endl;
        f(i,n/4+1,n/4+n/2+1)cout << i << " ";cout << endl;
    }
    else no;
}