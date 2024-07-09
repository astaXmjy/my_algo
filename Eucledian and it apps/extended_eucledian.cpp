#include <bits/stdc++.h>
using namespace std;

vector<int> extended_gcd(int a, int b)
{
    if (b == 0)
        return {1, 0 ,a};
    vector<int> res = extended_gcd(b, a % b);
    int smallX = res[0];
    int smallY = res[1];
    int gcd=res[2];
    int x = smallY;
    int y = smallX - (a / b) * smallY;

    return {x, y,gcd};
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int x, y;
    vector<int> res = extended_gcd(a, b);
    cout << res[0] << " and " << res[1] <<" gcd:"<<res[2]<<endl;
    return 0;
}
