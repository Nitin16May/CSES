#include <bits/stdc++.h>
using namespace std;
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
template <typename treetype>class segtree
{
    public:
    treetype operation(treetype operand1,treetype operand2)
    {
        return {min(operand1.first,operand2.first),min(operand1.second,operand2.second)};
    }
    void merge(int pos)
    {
        if(pos<=N-1)nodes[pos]=operation(nodes[2*pos],nodes[2*pos+1]);
    }
    vector<treetype> nodes;
    int N,n,lol;
    treetype default_value;
    segtree(int si,treetype temp)
    {
        n=si;N=n;
        if(N & (N - 1))N=0x8000000000000000 >> (__builtin_clzll(N) - 1);
        if(N==1)N=2;
        nodes.assign(N*2+5,temp);
        default_value=temp;
    };
    void input()
    {
        int x;
        f(i,1,n)cin >> x,nodes[N+i-1]={x-i,x+i};
        fr(i,N-1,1)merge(i);
    }
    treetype query(int start,int end)
    {
        return pvquery(1,start,end,1,N);
    }
    void update(int destination,treetype value)
    {
        pointupdate(1,1,N,destination,value);
        return;
    }
    private:
    treetype pvquery(int pos,int start,int end,int present_start,int present_end)
    {
        if(present_end<=end && present_start>=start)return nodes[pos];
        if(present_end<start || present_start>end)return default_value;
        return operation(pvquery(pos*2,start,end,present_start,present_start+(present_end-present_start+1)/2-1),pvquery(pos*2+1,start,end,present_start+(present_end-present_start+1)/2,present_end));
    }
    treetype pointupdate(int pos,int present_start,int present_end,int destination,treetype value)
    {
        if(present_end<destination || present_start>destination)return nodes[pos];
        if(present_end==present_start)nodes[pos]=value;
        else
        {
            nodes[pos*2]=pointupdate(pos*2,present_start,present_start+(present_end-present_start+1)/2-1,destination,value);
            nodes[pos*2+1]=pointupdate(pos*2+1,present_start+(present_end-present_start+1)/2,present_end,destination,value);
            merge(pos);
        }
        return nodes[pos];
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
    int n,k,m;
    cin >> n >> k;
    segtree<pair<int,int>> a(n,{1e10,1e10});
    a.input();
    while(k--)
    {
        cin >> n;
        if(n==1)
        {
            cin >> n >> m;
            a.update(n,{m-n,m+n});
        }
        else
        {
            cin >> m;
            cout << min(a.query(1,m).first+m,a.query(m+1,a.n).second-m) << endl;
        }
    }
}