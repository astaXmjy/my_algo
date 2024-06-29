#include <bits/stdc++.h>
using namespace std;

void factorize(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }

            cout << i << "^" << cnt << ",";
        }
    }
}

void fact_optimize(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            cout << i << "^" << cnt << ",";
        }
    }
    if (n != 1)
    {
        cout << n << "^" << 1 << " ";
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    fact_optimize(n);
    return 0;
}
