#include <bits/stdc++.h>
using namespace std;

void primenos(vector<int> &p)
{
    for (int i = 2; i < p.size(); i++)
    {
        if (p[i] != 0)
        {
            for (int j = i * i; j < p.size(); j += i)
            {
                p[j] = 0;
            }
        }
    }
}

struct sgTree
{

    int n;
    vector<int> st;

    void init(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
    }

    void build(int s, int e, int node, vector<int> &v, vector<int> &p)
    {
        if (s == e)
        {
            st[node] = p[v[s]];
            return;
        }
        int mid = (s + e) / 2;

        build(s, mid, 2 * node + 1, v, p);
        build(mid + 1, e, 2 * node + 2, v, p);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(vector<int> &v, vector<int> &p)
    {
        build(0, n - 1, 0, v, p);
    }

    int query(int l, int r, int s, int e, int node)
    {
        if (s > r or e < l)
        {
            return 0;
        }
        if (s >= l and e <= r)
        {
            return st[node];
        }

        int mid = (s + e) / 2;

        int q1 = query(l, r, s, mid, 2 * node + 1);
        int q2 = query(l, r, mid + 1, e, 2 * node + 2);

        return q1 + q2;
    }

    int query(int l, int r)
    {
        return query(l, r, 0, n - 1, 0);
    }

    void update(int s, int e, int node, int x, int y,vector<int>&p)
    {
         if(s==e)
         {
             st[node]=p[y];
             return;
         }
         int mid = (s + e) / 2;

         if(x<=mid){
             update(s, mid, 2 * node + 1, x, y,p);

         }
          else{
              update(mid + 1, e, 2 * node + 2, x, y,p);
          }

          st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void update(int x, int y,vector<int>& p)
    {
        // x is index and y is value
        update(0, n - 1, 0, x, y,p);
    }
};

int main(int argc, char const *argv[])
{
    int n = 1e7;
    vector<int> p(n + 1, 1);

    vector<int> v{2, 3, 4, 7, 8, 10, 13};

    primenos(p);

    sgTree tree;

    tree.init(v.size());

    tree.build(v, p);

    tree.update(2, 17,p);

    cout << tree.query(0,1);

    return 0;
}
