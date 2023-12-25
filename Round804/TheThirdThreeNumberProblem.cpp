#include <iostream>

using namespace std;

// int nearMul2(int a)
// {
//   a |= (a >> 1);
//   a |= (a >> 2);
//   a |= (a >> 4);
//   a |= (a >> 8);
//   a |= (a >> 16);

//   return ((a + 1) >> 1);
// }

int main()
{
  int t{};
  cin >> t;
  while (t--)
  {
    int n{};
    cin >> n;
    if (n & 1)
    {
      cout << "-1\n";
      continue;
    }
    int n2{n >> 1};
    // int n3{nearMul2(n2)};
    // int n4{n2 ^ n3};
    int n3{n2};
    int n4{0};
    cout << n2 << ' ' << n3 << ' ' << n4 << '\n';
  }
  return 0;
}
