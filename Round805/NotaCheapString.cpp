#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void inputOutput()
{
  string str{};
  cin >> str;
  int p{};
  cin >> p;
  int summ{(int)str.size()};
  for (char ch : str)
    summ += ch - 'a';
  string res{""}, str1{str};
  if (summ <= p)
    res = str;
  else
  {
    sort(str1.begin(), str1.end(), greater<char>());
    int arr[26];
    for (int i{0}; i < 26; ++i)
      arr[i] = 0;
    for (char ch : str1)
    {
      summ -= ch - 'a' + 1;
      ++arr[ch - 'a'];
      if (summ <= p)
        break;
    }
    for (int i{0}; i < str.size(); ++i)
    {
      if (arr[str[i] - 'a'])
        --arr[str[i] - 'a'];
      else
        res.push_back(str[i]);
    }
  }
  cout << res << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  int t{};
  cin >> t;
  while (t--)
    inputOutput();
  return 0;
}
