#include <iostream>
using namespace std;

int main()
{
  int t{};
  cin >> t;
  while (t--)
  {
    int n{}, k{}, cnt{}, prev{}, pprev{}, now{};
    cin >> n >> k;
    cin >> pprev >> prev;
    for (int i{2}; i < n; ++i)
    {
      cin >> now;
      if (prev > pprev + now)
        ++cnt;
      pprev = prev;
      prev = now;
    }
    if (k == 1)
      cnt = (n - 1) >> 1;
    cout << cnt << '\n';
  }
  return 0;
}
