#include <bits/stdc++.h>
using namespace std;

// summation
struct segmentTree
{
    int n;
    vector<int> st;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build_helper(int s, int e, int node, vector<int> &v)
    {

        if (s == e)
        {
            st[node] = v[s];
            return;
        }
        int mid = (s + e) / 2;

        build_helper(s, mid, 2 * node + 1, v);

        build_helper(mid + 1, e, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    void build(vector<int> &v)
    {
        build_helper(0, v.size() - 1, 0, v);
    }

    int query(int start, int end, int l, int r, int node)
    {
        if (start > r || end < l)
            return 0;
        if (start >= l and end <= r)
        {
            return st[node];
        }
        int mid = (start + end) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);

        return q1 + q2;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int start, int end, int node, int index, int value)
    {

        if (start == end)
        {
            st[node] = value;
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid)
        {
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            update(mid + 1, end, 2 * node + 2, index, value);
        }

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    segmentTree tree;

    tree.init(v.size());

    tree.build(v);

    tree.update(2, 6);

    cout << tree.query(0, 4);

    return 0;
}
