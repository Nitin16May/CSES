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
        return (operand1+operand2);
    }
    void merge(int pos,int present_start,int present_end)
    {
        if(pos<=N-1)nodes[pos]=operation(nodes[2*pos],nodes[2*pos+1]);
    }
    void lazy_operation(int pos,int present_start,int present_end,treetype value)
    {
        pending[pos]+=value;
        pendingcount[pos]++;
    }
    void activate(int pos,int present_start,int present_end)
    {
        if(pendingcount[pos]==default_value_of_pending)return;
        nodes[pos]=nodes[pos]+pendingcount[pos]*(((present_end*(present_end+1))/2)-((present_start*(present_start-1))/2))-pending[pos]*(present_end-present_start+1);
        if(present_start<present_end)
        {
            pending[pos*2]+=pending[pos];
            pending[pos*2+1]+=pending[pos];
            pendingcount[pos*2]+=pendingcount[pos];
            pendingcount[pos*2+1]+=pendingcount[pos];
        }
        pending[pos]=default_value_of_pending;
        pendingcount[pos]=default_value_of_pending;
    }
    void input()
    {
        input(1,1,N);
    }
    int input(int pos,int present_start,int present_end)
    {
        if(present_end==present_start)
        {
            if(present_start<=n){cin >> nodes[pos];}
            else nodes[pos]=default_value;
        }
        else 
        {
            input(pos*2,present_start,present_start+(present_end-present_start+1)/2-1);
            input(pos*2+1,present_start+(present_end-present_start+1)/2,present_end);
            merge(pos,present_start,present_end);
        }
        return nodes[pos];
    }
    vector<treetype> nodes,pending,pendingcount;
    int N,n;
    treetype default_value,default_value_of_pending;
    segtree(int si,treetype temp,treetype temp2)
    {
        n=si;N=n;
        if(N & (N - 1))N=0x8000000000000000 >> (__builtin_clzll(N) - 1);
        if(N==1)N=2;
        nodes.assign(N*2+5,temp);
        pending.assign(N*2+5,temp2);
        pendingcount.assign(N*2+5,temp);
        default_value=temp;
        default_value_of_pending=temp2;
    };
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
    }
    void update(int start,int end,treetype value)
    {
        rangeupdate(1,1,N,start,end,value);
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
        NextTwo=1;count=0;
        f(i,1,N+N-1)
        {
            cout << pendingcount[i] << " ";
            count++;
            if(count==NextTwo)
            {
                cout << endl;
                NextTwo=NextTwo*2;count=0;
            }
        }
        cout << endl;cout << endl;
    }
    private:
    treetype pvquery(int pos,int start,int end,int present_start,int present_end)
    {
        activate(pos,present_start,present_end);
        if(present_end<=end && present_start>=start)return nodes[pos];
        if(present_end<start || present_start>end)return default_value;
        return operation(pvquery(pos*2,start,end,present_start,present_start+(present_end-present_start+1)/2-1),pvquery(pos*2+1,start,end,present_start+(present_end-present_start+1)/2,present_end));
    }
    treetype pointupdate(int pos,int present_start,int present_end,int destination,treetype value)
    {
        activate(pos,present_start,present_end);
        if(present_end<destination || present_start>destination)return nodes[pos];
        if(present_end==present_start)nodes[pos]=value;
        else
        {
            nodes[pos*2]=pointupdate(pos*2,present_start,present_start+(present_end-present_start+1)/2-1,destination,value);
            nodes[pos*2+1]=pointupdate(pos*2+1,present_start+(present_end-present_start+1)/2,present_end,destination,value);
            merge(pos,present_start,present_end);
        }
        return nodes[pos];
    }
    void rangeupdate(int pos,int present_start,int present_end,int start,int end,treetype value)
    {
        activate(pos,present_start,present_end);
        if(present_end<=end && present_start>=start)
        {
            lazy_operation(pos,present_start,present_end,value);
            activate(pos,present_start,present_end);
            return;
        }
        if(present_end<start || present_start>end)return;
        rangeupdate(pos*2,present_start,present_start+(present_end-present_start+1)/2-1,start,end,value);
        rangeupdate(pos*2+1,present_start+(present_end-present_start+1)/2,present_end,start,end,value);
        merge(pos,present_start,present_end);
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    int n,q,aa,b;
    cin >> n >> q;
    segtree<int> a(n,0,0);
    a.input();
    f(i,1,q)
    {
        cin >> n >> aa >> b;
        if(n==1)a.update(aa,b,aa-1);
        else cout << a.query(aa,b) << endl;
    }
}