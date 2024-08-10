#include <bits/stdc++.h>
using namespace std;

void generateBrackets(vector<string> &output, int n, int close, int open, int i, string &s)
{
    if (i == 2 * n)
    {
        output.push_back(s);
        return;
    }
    if (open < n)
    {
        s += '(';
        generateBrackets(output, n, close, open + 1, i + 1, s);
        s.pop_back();
    }
    if (close < open)
    {
        s += ')';
        generateBrackets(output, n, close + 1, open, i + 1, s);
        s.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    vector<string> output;
    int n;
    cin >> n;
    string s = "";
    generateBrackets(output, n, 0, 0, 0, s);

    for (int i = 0; i < output.size(); i++)
    {
         cout << output[i] << endl;
    }
    return 0;
} 
