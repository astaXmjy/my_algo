#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 9;
const int N = 1e5 + 5;

vector<vector<pair<int, int>>> segtree(4 * N);

vector<pair<int, int>> occurences(N);

vector<set<int>> pos(N);

int n;

void build(int node = 0, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        segtree[node].push_back(occurences[l]);
        return;
    }
    int mid = (l + r) / 2;

    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);

    merge(segtree[2 * node + 1].begin(),
          segtree[2 * node + 1].end(),
          segtree[2 * node + 2].begin(),
          segtree[2 * node + 2].end(),
          back_inserter(segtree[node]));

    int mx = 0;

    for (auto &i : segtree[node])
    {
        mx = max(mx, i.second);

        i.second = mx;
    }
}

bool query(int x, int y, int node = 0,
           int l = 0, int r = n - 1)
{
    if (l > y || r < x || x > y)
        return false;
    if (x <= l and r <= y)
    {
        auto it = lower_bound(segtree[node].begin(),
                              segtree[node].end(),
                              make_pair(x, -1));
        if (it == segtree[node].begin())
            return false;

        else
        {
            it--;
            if (it->second > y)
            {
                return true;
            }
            else
                return false;
        }
    }

    int mid = (l + r) / 2;
    bool a = query(x, y, 2 * node + 1, l, mid);
    bool b = query(x, y, 2 * node + 2, mid + 1, r);

    return (a | b);
}

void preprocess(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        pos[arr[i]].insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        auto it = pos[arr[i]].find(i);
        if (it == pos[arr[i]].begin())
        {
            occurences[i].first = -INF;
        }
        else
        {
            occurences[i].first = *prev(it);
        }
        if (next(it) == pos[arr[i]].end())
        {
            occurences[i].second = INF;
        }
        else
        {
            occurences[i].second = *next(it);
        }
    }
    build();
}

void answerquery(int arr[], vector<pair<int, int>> &queries)
{
    preprocess(arr);

    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i].first - 1;
        int r = queries[i].second - 1;

        bool there = query(l, r);

        if (there == true)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

int main()
{
    int arr[] = {1, 2, 1, 2, 3, 4};

    n = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int, int>> queries = {{1, 4}, {1, 5}};

    answerquery(arr, queries);

    return 0;
}