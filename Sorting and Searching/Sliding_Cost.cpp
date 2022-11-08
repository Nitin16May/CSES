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
struct cmp
{
	bool operator()(const int& x, const int& y) const 
    { 
        return x>y;
    }
};  
 
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,k,d=0,s1=0,s2=0,m,ans;
    cin >> n >> k;
    vector<int> a(n+1);
    f(i,1,n)cin >> a[i];a[0]=0;
    oset<pair<int,int>> hmm;
    multiset<int,cmp> l1;l1.insert(0);
    multiset<int> l2;l2.insert(2e9);
    f(i,0,k-1)hmm.insert({a[i],i});
    for(auto i:hmm)l1.insert(i.first),s1+=i.first;
    f(i,k,n)
    {
        hmm.insert({a[i],i});
        hmm.erase({a[d],d});
        l1.insert(a[i]);s1+=a[i];
        if(l1.find(a[d])==l1.end())l2.erase(l2.find(a[d])),s2-=a[d];
        else l1.erase(l1.find(a[d])),s1-=a[d];
        m=(*hmm.find_by_order(k/2)).first;
        if(l1.size()){while(*l1.begin()>m){l2.insert(*l1.begin());s1-=*l1.begin();s2+=*l1.begin();l1.erase(l1.begin());}}
        if(l2.size()){while(*l2.begin()<m){l1.insert(*l2.begin());s1+=*l2.begin();s2-=*l2.begin();l2.erase(l2.begin());}}
        ans=(sz(l1)*m-s1+s2-sz(l2)*m);
        m=(*hmm.find_by_order((k-1)/2)).first;
        if(l1.size()){while(*l1.begin()>m){l2.insert(*l1.begin());s1-=*l1.begin();s2+=*l1.begin();l1.erase(l1.begin());}}
        if(l2.size()){while(*l2.begin()<m){l1.insert(*l2.begin());s1+=*l2.begin();s2-=*l2.begin();l2.erase(l2.begin());}}
        ans=min((sz(l1)*m-s1+s2-sz(l2)*m),ans);
        cout << ans << " ";d++;
    }
}