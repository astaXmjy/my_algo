#include <bits/stdc++.h>
using namespace std;

// having one uniq num

int uniq_num(vector<int> &num)
{

    int ans = 0;

    for (int i = 0; i < num.size(); i++)
    {
        ans ^= num[i];
    }

    return ans;
}

// having two uniq num

void uniq_num_2(vector<int> &num)
{
    int ans = 0;
    int n = num.size();

    for (int i = 0; i < n; i++)
    {
        ans ^= num[i];
    }

    int pos = 0;

    int temp = ans;

    while ((temp & 1) == 0)
    {
        pos++;
        temp = temp >> 1;
    }

    int setA = 0;
    int setB = 0;

    for (int i = 0; i < n; i++)
    {
        if (num[i] >> pos & 1 != 0)
        {
            setA ^= num[i];
        }
        else
        {
            setB = setB ^ num[i];
        }
    }

    cout << setA << endl;
    cout << setB << endl;
}

// having 1 uniq num all other comes thrice

int uniq_num_3(vector<int> &num)
{
    vector<int> temp(32, 0);
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < 32; j++)
        {
            int ith_bit = num[i] & (1 << j);
            if (ith_bit)
            {
                temp[j]++;
            }
        }

        for (int i = 0; i < 32; i++)
        {
            temp[i] = temp[i] % 3;
        }
    }
    int numAns = 0;
    for (int i = 0; i < 32; i++)
    {
        numAns += (temp[i] * (1 << i));
    }

    return numAns;
}

int main(int argc, char const *argv[])
{
    vector<int> num{3, 3, 2, 2, 14, 2, 14, 14, 4, 3};
    // cout<< uniq_num(num);

    uniq_num_2(num);
    cout << uniq_num_3(num);

    return 0;
}