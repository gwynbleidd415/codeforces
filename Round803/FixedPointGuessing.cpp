#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

bool callHelp(int l, int r)
{
  cout << "? " << l << ' ' << r << '\n';
  cout.flush();
  int n{r - l + 1}, temp{}, ans{0};
  for (int i{0}; i < n; ++i)
  {
    cin >> temp;
    if (temp >= l && temp <= r)
      ++ans;
  }
  return ans & 1;
}

int main()
{
  int t{};
  cin >> t;
  while (t--)
  {
    int n{};
    cin >> n;
    int l{1}, r{n}, mid{};
    while (l != r)
    {
      mid = (l + r) >> 1;
      if (callHelp(l, mid))
        r = mid;
      else
        l = mid + 1;
    }
    cout << "! " << l << '\n';
  }
  return 0;
}
