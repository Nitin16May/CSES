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
//////*************Nitin1605***************//////
template <typename treetype>class segtree
{
    public:
    treetype operation(treetype operand1,treetype operand2)
    {
        return min(operand1,operand2);
    }
    void merge(int pos)
    {
        if(pos<=N-1)nodes[pos]=operation(nodes[2*pos],nodes[2*pos+1]);
    }
    void lazy_operation(int pos,int present_start,int present_end,treetype value)
    {
        pending[pos]+=value;
    }
    vector<treetype> nodes,pending;
    int N,n;
    treetype default_value,default_value_of_pending;
    bool is_lazy;
    segtree(int si,treetype temp)
    {
        n=si;N=n;
        if(N & (N - 1))N=0x8000000000000000 >> (__builtin_clzll(N) - 1);
        nodes.assign(N*2+5,temp);
        default_value=temp;
        is_lazy=false;
    };
    void make_lazy(treetype temp)
    {
        is_lazy=true;
        pending.assign(N*2+5,temp);
        default_value_of_pending=temp;
    }
    void activate(int pos)
    {
        if(pending[pos]==default_value_of_pending)return;
        nodes[pos]=nodes[pos]+pending[pos];
        if(pos<=N-1)
        {
            pending[pos*2]+=pending[pos];
            pending[pos*2+1]+=pending[pos];
        }
        pending[pos]=default_value_of_pending;
    }
    void input()
    {
        f(i,1,n)cin >> nodes[N+i-1];
        fr(i,N-1,1)merge(i);
    }
    treetype query(int start,int end)
    {
        return pvquery(1,start,end,1,N);
    }
    treetype query(int pos)
    {
        return pvquery(1,pos,pos,1,N);
    }
    void update(int destination,treetype value)
    {
        pointupdate(1,1,N,destination,value);
        return;
    }
    void update(int start,int end,treetype value)
    {
        if(is_lazy)rangeupdate(1,1,N,start,end,value);
        else cout << "Lazy not Declared\n";
        return;
    }
    void printtree()
    {
        int NextTwo=1,count=0;
        f(i,1,N+N-1)
        {
            cout << nodes[i] << " ";
            count++;
            if(count==NextTwo)
            {
                cout << endl;
                NextTwo=NextTwo*2;count=0;
            }
        }
        cout << endl;
        if(is_lazy==false)return;
        NextTwo=1;count=0;
        f(i,1,N+N-1)
        {
            cout << pending[i] << " ";
            count++;
            if(count==NextTwo)
            {
                cout << endl;
                NextTwo=NextTwo*2;count=0;
            }
        }
        cout << endl;
    }
    private:
    treetype pvquery(int pos,int start,int end,int present_start,int present_end)
    {
        if(is_lazy)activate(pos);
        if(present_end<=end && present_start>=start)return nodes[pos];
        if(present_end<start || present_start>end)return default_value;
        return operation(pvquery(pos*2,start,end,present_start,present_start+(present_end-present_start+1)/2-1),pvquery(pos*2+1,start,end,present_start+(present_end-present_start+1)/2,present_end));
    }
    treetype pointupdate(int pos,int present_start,int present_end,int destination,treetype value)
    {
        if(is_lazy)activate(pos);
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
    void rangeupdate(int pos,int present_start,int present_end,int start,int end,treetype value)
    {
        if(present_end<=end && present_start>=start)
        {
            lazy_operation(pos,present_start,present_end,value);
            return;
        }
        if(present_end<start || present_start>end)return;
        rangeupdate(pos*2,present_start,present_start+(present_end-present_start+1)/2-1,start,end,value);
        rangeupdate(pos*2+1,present_start+(present_end-present_start+1)/2,present_end,start,end,value);
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
    int n,q,aa,b,c;
    cin >> n >> q;
    segtree<int> a(n,1e18);
    a.make_lazy(0);
    a.input();
    while(q--)
    {
        cin >> n;
        if(n==1){cin >> aa >> b >> c;a.update(aa,b,c);}
        else{cin >> aa;cout << a.query(aa) << endl;}
        //a.printtree();
    }
}