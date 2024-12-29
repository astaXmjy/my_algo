#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N], grr[N];
int vis[N], col[N];
vector<int> order;
vector<int> components[N];

void dfs1(int curr)
{
    vis[curr] = 1;
    for (auto x : gr[curr])
    {
        if (!vis[x])
            dfs1(x);
    }

    order.push_back(curr);
}

void dfs2(int cur, int comp)
{
    vis[cur] = 1;
    col[cur] = comp;
    components[comp].push_back(cur);
    for (auto x : grr[cur])
    {
        if (!vis[x])
            dfs2(x, comp);
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);// graph
        grr[y].push_back(x); // reverse graph
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs1(i);
    }

    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof(vis));

    int comp = 1;

    for (auto x : order)
    {
        if (!vis[x])
            dfs2(x, comp++);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << col[i] << '\n';
    }

    cout << "Totally strong connected components are ----->" << comp-1 << '\n';
    return 0;
}
