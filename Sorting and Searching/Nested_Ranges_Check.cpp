#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define int long long
#define uint unsigned long long
#define float long double
#define double long double
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(int i = a; i <= b; i++)
#define fr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
//////*************Nitin1605***************//////
bool peace(array<int,3> x,array<int,3> y)
{
    if(x[0]<y[0])return true;
    else if(x[0]==y[0] && y[1]<x[1])return true;
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n;
    cin >> n;
    vector<array<int,3>> r(n);
    f(i,0,n-1)cin >> r[i][0] >> r[i][1],r[i][2]=i;
    sort(all(r),peace);
    oset<pair<int,int>> x;
    vector<int> a(n,0),b(n,0);
    fr(i,n-1,0)
    {
        a[r[i][2]]=x.order_of_key({r[i][1]+1,-1});
        x.insert({r[i][1],r[i][2]});
    }
    x.clear();
    f(i,0,n-1)
    {
        b[r[i][2]]=x.size()-x.order_of_key({r[i][1],-1});
        x.insert({r[i][1],r[i][2]});
    }
    f(i,0,n-1)cout << min(a[i],1ll) << " ";cout << endl;
    f(i,0,n-1)cout << min(b[i],1ll) << " ";cout << endl;
}