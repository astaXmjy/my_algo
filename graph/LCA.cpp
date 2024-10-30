#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int dep[N], Par[N];

void dfs(int cur, int par)
{
    Par[cur] = par;
    dep[cur] = dep[par] + 1;
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
        }
    }
}
int LCA(int u, int v)
{
    if (u == v)
        return u;

    if (dep[u] < dep[v])
        swap(u, v);

    int diff = dep[u] - dep[v];
    while (diff--)
    {
        u = Par[u];
    }

    while (u != v)
    {
        u = Par[u];
        v = Par[v];
    }

    return u;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << dep[i] << '\n';
    }

    cout << LCA(9, 12);

    return 0;
}
