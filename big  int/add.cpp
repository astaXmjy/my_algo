#include <bits/stdc++.h>
using namespace std;

int char_to_digit(char c)
{
  return c - '0';
}

char digit_to_char(int n)
{
  return n + '0';
}

string addition(string &n1, string &n2)
{
  string res = "";

  if (n1.size() > n2.size())
  {
    swap(n1, n2);
  }

  int carry = 0;

  reverse(n1.begin(), n1.end());
  reverse(n2.begin(), n2.end());

  for (int i = 0; i < n1.size(); i++)
  {
    int sum = char_to_digit(n1[i]) + char_to_digit(n2[i]) + carry;
    int digit = sum % 10;
    carry = sum / 10;
    res.push_back(digit_to_char(digit));
  }

  for (int i = n1.length(); i < n2.length(); i++)
  {
    int sum = char_to_digit(n2[i]) + carry;
    int digit = sum % 10;
    carry = sum / 10;
    res.push_back(char_to_digit(digit));
  }

  if (carry)
  {
    res.push_back('1');
  }

  reverse(res.begin(), res.end());

  return res;
}

int main(int argc, char const *argv[])
{
  string s1 = "1111111";
  string s2 = "2222222";
  cout << addition(s1, s2);
  return 0;
}
