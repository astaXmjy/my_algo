#include <bits/stdc++.h>
using namespace std;

void update(int *a, int *b, int index, int x, int m)
{
    b[index / m] += x - a[index];
    a[index] = x;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int m = sqrt(n) + 1;

    int a[n], b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i / m] += a[i];
    }


    int q;

    cin >> q;

    while (q--)
    {
        int l, r, ans = 0;
        cin >> l >> r;

        for (int i = l; i <= r;)
        {
            if (i % m == 0 and i + m - 1 <= r)
            {
                ans += b[i / m];
                i += m;
            }
            else
            {
                ans += a[i];
                i += 1;
            }
        }

        cout << ans << endl;
    }

    update(a, b, 1, 2, m);

    cout << a[1] << endl;
    return 0;
}
