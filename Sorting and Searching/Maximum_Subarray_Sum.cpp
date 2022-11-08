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
ll n;
vec arr;
void LargestSumSubarray()
{
    //change arr
    ll max_so_far=LLONG_MIN,max_ending_here=0,start=0,end=0,maybe_start=0;
    for (ll j=0;j<n;j++)
    {
        max_ending_here=max_ending_here+arr[j];
        if(max_ending_here<arr[j]){max_ending_here=arr[j];maybe_start=j+1;}
        if(max_so_far<max_ending_here){max_so_far=max_ending_here;start=maybe_start;end=j+1;}
    }
    //max_so_far-->largest sum
    //start------->starting index
    //end--------->ending index
    cout << max_so_far;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ll x;
    cin>>n;
    f(test,1,n)
    {
        cin >> x;
        arr.pb(x);
    }
    LargestSumSubarray();
}