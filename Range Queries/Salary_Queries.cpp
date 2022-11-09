
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
#define vec vector<int>
#define dvec vector<vector<int>>
//////*************Nitin1605***************//////

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,q,m;char ch;
    cin >> n >> q;
    oset<pair<int,int>> a;
    vector<int> lol(n);
    f(i,1,n)cin >> lol[i-1],a.insert({lol[i-1],i});
    while(q--)
    {
        cin >> ch >> n >> m;
        if(ch=='!')
        {
            a.erase(a.find({lol[n-1],n}));
            a.insert({m,n});
            lol[n-1]=m;
        }
        else cout << a.order_of_key({m+1,0}) - a.order_of_key({n,0}) << endl;
    }
}