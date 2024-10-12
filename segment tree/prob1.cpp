#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
    int n;
    vector<int> st;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
    }
    void build(vector<int> &v, int start, int end, int node, int check)
    {

        if (start == end)
        {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;

        build(v, start, mid, 2 * node + 1, check - 1);
        build(v, mid + 1, v.size() - 1, 2 * node + 2, check - 1);

        if (check % 2)
        {
            st[node] = st[2 * node + 1] | st[2 * node + 2];
        }
        else
        {
            st[node] = st[2 * node + 1] ^ st[2 * node + 2];
        }
    }
    void build(vector<int> &v,int check)
    {
        build(v, 0, v.size() - 1, 0, check);
    }

    void update(int value,int index,int start,int end,int node,int check){


       if(start==end){
           st[node] = value;
           return;
       }

        int mid = (start + end) / 2;

        if(index<=mid){
            update(value, index, start, mid, 2 * node + 1,check-1);
        }

        else{
            update(value, index, mid + 1, end, 2 * node + 2,check-1);
        }

        if(check%2){
            st[node] = st[2 * node + 1] | st[2 * node + 2];
        }
        else{
            st[node] = st[2 * node + 1] ^ st[2 * node + 2];
        }
    }

    void update(int index,int value,int check){
        update(value,index, 0, n-1,0,check);
    }
};

int main(int argc, char const *argv[])
{
    int n, m, p, b, ans;
    cin >> n >> m;
    int lim = 1 << n;
    vector<int> v(lim,0);

    for (int i = 0; i < v.size(); i++)
    {
        int x;
        cin >> x;
        v[i] = x;
    }

    SegmentTree tree;
    tree.init(v.size());

    tree.build(v, n);



    while (m--)
    {
        cin >> p >> b;

        tree.update(b,p,n);

        ans = tree.st[0];

        cout << ans << endl;
    }


    return 0;
}
