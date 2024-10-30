#include <bits/stdc++.h>
using namespace std;

struct fenwick
{
    vector<int> fn;
    int n;

    void init(int n)
    {
        this->n = n + 1;
        fn.resize(this->n, 0);
    }

    void add(int x, int y)
    {
        for (x++; x < n; x += (x & (-x)))
        {
            fn[x] += y;
        }
    }
    int sum(int x)
    {
        int ans = 0;
        for (x++; x > 0; x -= (x & (-x)))
        {
            ans += fn[x];
        }

        return ans;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    pair<int, int> a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);

    fenwick tree;
    tree.init(n);

    int inversion_count = 0, b[n];

    for (int i = 0; i < n; i++)
    {
        int element = a[i].first;
        int index = a[i].second;

        b[index] = tree.sum(index + 1, n - 1);
        inversion_count += b[index];
        tree.add(index, 1);
    }

    cout << inversion_count << endl;

    return 0;
}
