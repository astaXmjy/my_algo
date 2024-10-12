#include <bits/stdc++.h>
using namespace std;

int shortest_path(string start, string finish, int n)
{
    unordered_map<string, bool> vis;
    unordered_map<string, string> src;
    unordered_map<string, int> d;

    queue<string> q;

    q.push(start);
    q.push(finish);

    vis[start] = true;
    vis[finish] = true;

    src[start] = start;
    src[finish] = finish;

    d[start] = d[finish] = 0;



    while (!q.empty())
    {
        cout << "in" << endl;
        string u = q.front();
        q.pop();

        for (int i = 1; i < n; i++)
        {
            string v = u;
            swap(v[i - 1], v[i]);

            if (!vis[v])
            {
                vis[v] = true;
                src[v] = src[u];
                d[v] = d[u] + 1;
                q.push(v);
            }
            else if (src[u] != src[v])
            {
                return d[u] + d[v] + 1;
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    string p1 = "213", p2 = "321";
    int n = p1.length();

    cout << shortest_path(p1, p2, n);

    return 0;
}
