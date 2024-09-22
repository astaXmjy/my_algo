#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int a = 0, b = 1, c;
    if (n == 0)
    {
        return a;
    }
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int fib2(int n){
    if(n==0){
        return 0;
    }
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <n+1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    cout << fib(5)<<" "<<fib2(5)<< endl;
    return 0;
}
