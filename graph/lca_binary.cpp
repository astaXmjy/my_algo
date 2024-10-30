#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, M = 20;
vector<int> gr[N];
int dep[N], Par[N][M];

void dfs(int cur, int par)
{
    dep[cur] = dep[par] + 1;

    Par[cur][0] = par;
    for (int j = 1; j < M; j++)
    {
        Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    }

    for (auto x : gr[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
        }
    }
}

int lca(int u, int v)
{
    if (u == v)
        return u;
    if (dep[u] < dep[v])
        swap(u, v);

    int diff = dep[u] - dep[v];
    for (int i = M - 1; i >= 0; i--)
    {
        if (diff >> i & 1)
        {
            u = Par[u][i];
        }
    }

    for (int j = M - 1; j >= 0; j--)
    {
        if (Par[u][j] != Par[v][j])
        {
            u = Par[u][j];
            v = Par[v][j];
        }
    }

    return Par[u][0];
}

int main(int argc, char const *argv[])
{

    return 0;
}
