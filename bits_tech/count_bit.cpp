#include <bits/stdc++.h>
using namespace std;

int set_bit_count(int &n)
{
    int count = 0;

    while (n)
    {
        if (n & 1 == 1)
            count++;
        n = n >> 1;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    int n = 3;

    int count_of_set_bits = set_bit_count(n);
    cout << count_of_set_bits;
    return 0;
}
