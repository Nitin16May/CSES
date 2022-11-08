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
vec a,b;
void towerOfHanoi(int n,int from_rod,int to_rod,int aux_rod)
{
    if (n == 0)return;
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    a.pb(from_rod);b.pb(to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
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
        towerOfHanoi(n,1,3,2);
        cout << a.size() << endl;
        f(i,0,a.size()-1)cout << a[i] << " " << b[i] << endl;
    }
}