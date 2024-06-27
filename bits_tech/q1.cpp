#include <bits/stdc++.h>
using namespace std;

// replce bits of n with m;

void solution(int &n, int &m, int i, int j)
{
    // first clear bits btw i and j
    int a = (~0) << (j + 1);
    int b = (i << 1) - 1;

    int mask1 = a | b;

    n = n & mask1;

    // replace bits

    int mask2 = (m << i);

    n = n | mask2;
}

int main(int argc, char const *argv[])
{
    int N = 1000000000;
    int M = 10101;

    solution(N, M, 2, 6);

    cout << N;

    return 0;
}
