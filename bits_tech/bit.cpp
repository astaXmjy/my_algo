#include <bits/stdc++.h>
using namespace std;

void clearBitsInRange(int &n, int i, int j)
{
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;

    int mask = a | b;

    n = n & mask;
}

int main(int argc, char const *argv[])
{
    int n = 45;
    clearBitsInRange(n, 2, 4);
    cout << (2^3^1);
    return 0;
}
