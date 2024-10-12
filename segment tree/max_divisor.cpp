#include <bits/stdc++.h>
using namespace std;

#define maxn 1000005
#define INF 99999999

int smallest_prime[maxn];
int divisors[maxn];
int segTree[4 * maxn];

void find_smallest_prime_factors()
{
    for (int i = 0; i < maxn; i++)
    {
        smallest_prime[i] = INF;
    }

    for (long long i = 2; i < maxn; i++)
    {
        if (smallest_prime[i] == INF)
        {
            smallest_prime[i] = i;
            for (long long j = i * i; j < maxn; j += i)
            {
                if (smallest_prime[j] > i)
                {
                    smallest_prime[j] = i;
                }
            }
        }
    }
}

void build_divisor_array()
{
    for (int i = 1; i < maxn; i++)
    {
        divisors[i] = 1;
        int n = i, p = smallest_prime[i], k = 0;

        while (n > 1)
        {
            n = n / p;
            k++;
            if (smallest_prime[n] != p)
            {
                divisors[i] = divisors[i] * (k + 1);
                k = 0;
            }

            p = smallest_prime[n];
        }
    }
}

void build_sgtree(int node, int a, int b)
{
    if (a == b)
    {
        segTree[node] = divisors[a];
        return;
    }
    build_sgtree(2 * node, a, (a + b) / 2);
    build_sgtree(2 * node + 1, ((a + b) / 2) + 1, b);

    segTree[node] = max(segTree[2 * node],
                        segTree[2 * node + 1]);
}

int query(int node, int a, int b, int l, int r)
{
    if (l > b or a > r)
    {
        return -1;
    }

    if (a >= l and b <= r)
        return segTree[node];

    return max(query(2 * node, a, (a + b) / 2, l, r),
               query(2 * node + 1, ((a + b) / 2) + 1, b, l, r));
}

int main(int argc, char const *argv[])
{
    find_smallest_prime_factors();

    build_divisor_array();

    build_sgtree(1, 1, maxn - 1);

    cout << "Maximum divisors that a number has " << " in [ 1, 100 ] are " << query(1, 1, maxn - 1, 1, 100) << endl;
    return 0;
}
