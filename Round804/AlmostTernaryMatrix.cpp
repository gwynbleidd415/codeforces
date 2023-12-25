#include <iostream>

using namespace std;

int main()
{
  int t{};
  cin >> t;
  while (t--)
  {
    int n{}, m{};
    cin >> n >> m;
    int temp{};
    for (int i{1}; i <= n; ++i)
    {
      temp = i >> 1;
      for (int j{1}; j <= m; ++j)
      {
        if ((temp & 1) == ((j >> 1) & 1))
          cout << "1 ";
        else
          cout << "0 ";
      }
      cout << '\n';
    }
  }
  return 0;
}
