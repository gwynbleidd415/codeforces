#include <iostream>

using namespace std;

void inputOutput()
{
  int m{};
  cin >> m;
  int n{m / 10}, o{1};
  while (n)
  {
    o *= 10;
    n /= 10;
  }
  cout << m - o << '\n';
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
