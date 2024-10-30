#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
vector<int> order;
int vis[N];

void dfs(int cur, int par)
{
    vis[cur] = 1;
    for (auto x : gr[cur])
    {
        if (!vis[x])
        {
            dfs(cur, x);
        }
    }
    order.push_back(cur);

    return;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 0);
    }

    reverse(order.begin(), order.end());

    for (auto x : order)
        cout << x << " ";
    return 0;
}
