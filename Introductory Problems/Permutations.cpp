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

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    ll n=1,a=1,b,c=0;
    cin>>n;b=llceil(n,2)+1;
    if(n==1)cout << "1";
    else if(n==2 || n==3)cout << "NO SOLUTION";
    else if(n==4)cout << "2 4 1 3";
    else 
    {
        while(true)
        {
            if(c==n)break;
            cout << a++ << " ";c++;
            if(c==n)break;
            cout << b++ << " ";c++;
        }
    }
}