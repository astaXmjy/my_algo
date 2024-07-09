#include <bits/stdc++.h>
using namespace std;

int no_ways_to_fill_tiles(int n)
{
    if (n < 4)
        return 1;
    return no_ways_to_fill_tiles(n - 1) + no_ways_to_fill_tiles(n - 4);
}

int main(int argc, char const *argv[])
{
    cout << no_ways_to_fill_tiles(4) << endl;

    return 0;
}
