#include <bits/stdc++.h>
using namespace std;

bool is_pow_2(int &n)
{
    if ((n & (n - 1)) == 0)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    bool ans = is_pow_2(n);

    cout << ans;

    return 0;
}
