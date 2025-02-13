#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int p = 31, mod = 1e9 + 7;

int poly_hash(string s)
{
    int has = 0;
    int p_pow = 1;
    for (int i = 0; i < s.size(); i++)
    {
        has += (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
        has %= mod;
        p_pow %= mod;
    }

    return has;
}

int powr(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        b /= 2;
        a *= a;
        a %= mod;
        res %= mod;
    }

    return res;
}

int inv(int x)
{
    return powr(x, mod - 2);
}

int32_t main()
{
    string text = "assdfasdfsdafjhj";
    string pattern = "fasd";

    int pat_hash = poly_hash(pattern);

    int n = text.size(), m = pattern.size();
    int text_hash = poly_hash(text.substr(0, m));

    if (pat_hash == text_hash)
    {
        cout << 0 << '\n';
    }

    for (int i = 1; i + m <= n; i++)
    {
        text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod) % mod;

        text_hash = (text_hash * inv(p)) % mod;

        text_hash = (text_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;

        if(text_hash == pat_hash){
            cout << i << '\n';
        }
    }

    return 0;
}
