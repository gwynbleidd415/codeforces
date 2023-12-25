#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main()
{
  int t{};
  cin >> t;
  while (t--)
  {
    int n{};
    ll temp{};
    cin >> n;
    vector<ll> non0;
    bool isPossible{false};
    for (int i{0}; i < n; ++i)
    {
      cin >> temp;
      if (temp)
        non0.push_back(temp);
    }
    if (non0.size() <= 1 || (non0.size() == 2 && non0.front() == -non0.back()))
      isPossible = true;
    else if (n == 3 && (non0[0] == -non0[1] || non0[0] == -non0[2] || non0[1] == -non0[2]))
      isPossible = true;
    else if (n == 4 && non0.size() == 4)
    {
      int summ{};
      bool areAllPresent{true}, isPresent{};
      for (int i{0}; i < 2; ++i)
      {
        for (int j{i + 1}; j < 3; ++j)
        {
          for (int k{j + 1}; k < 4; ++k)
          {
            summ = non0[i] + non0[j] + non0[k];
            isPresent = false;
            for (int itr : non0)
            {
              if (itr == summ)
              {
                isPresent = true;
                break;
              }
            }
            if (!isPresent)
            {
              areAllPresent = false;
              break;
            }
          }
        }
      }
      if (areAllPresent)
      {
        isPossible = areAllPresent;
      }
    }
    if (isPossible)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
