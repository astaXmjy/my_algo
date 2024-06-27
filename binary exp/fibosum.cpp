#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int mod = 1e9 + 7;

const int sz = 2;

struct Mat
{
    int m[sz][sz];
    Mat()
    {
        memset(m, 0, sizeof(m));
    }
    void identity()
    {
        for (int i = 0; i < sz; i++)
        {
            m[i][i] = 1;
        }
    }
    Mat operator*(Mat a)
    {
        Mat res;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    res.m[i][j] += m[i][j] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};


int fib(int n)
{   int time_coplexity=0;
    Mat res;
    res.identity();
    Mat T;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;
    if (n <= 2)
        return 1;

    n -= 2;

    while (n)
    {   time_coplexity++;
        if (n & 1)
        {
            res = res * T;
        }
        T = T * T;
        n /= 2;
    }

    cout<<time_coplexity<<endl;

    return (res.m[0][0]+res.m[0][1])%mod;
}

int fibosum(int n){
    int ans=0;




    return ans;
}

int32_t main()
{
    cout<<fib(1e6+7)<<endl;
    return 0;
}
