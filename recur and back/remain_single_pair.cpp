#include <bits/stdc++.h>
using namespace std;

int no_ways_to_be_single(int n)
{

    if (n == 0 or n == 1)
        return 1;

    return no_ways_to_be_single(n - 1) + (n - 1) * no_ways_to_be_single(n - 2);
}

int main(int argc, char const *argv[])
{
    cout << no_ways_to_be_single(3);
    return 0;
}
