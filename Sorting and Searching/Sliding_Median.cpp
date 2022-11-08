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

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,k,p,s=0;
    cin >> n >> k;p=(k-1)/2;
    vector<int> v(n);
    oset<pair<int,int>> a;
    f(i,0,n-1)cin >> v[i];
    f(i,0,k-1)a.insert({v[i],i});
    cout << (*a.find_by_order(p)).first << " ";
    f(i,k,n-1)
    {
        a.erase({v[s],s});s++;
        a.insert({v[i],i});
        cout << (*a.find_by_order(p)).first << " ";
    }
}