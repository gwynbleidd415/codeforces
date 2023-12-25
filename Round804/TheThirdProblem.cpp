#include <iostream>
#include <vector>

using namespace std;

int mod{(int)1e9 + 7};

int main()
{
  int t{};
  cin >> t;
  while (t--)
  {
    int n{};
    cin >> n;
    vector<int> arr(n);
    int temp{};
    for (int i{0}; i < n; ++i)
    {
      cin >> temp;
      arr[temp] = i;
    }
    int l{arr[0]}, r{arr[1]};
    long long int res{1};
    if (r < l)
      swap(l, r);
    for (int i{2}; i < n; ++i)
    {
      if (l < arr[i] && r > arr[i])
        res = (res * (r - l + 1 - i)) % mod;
      else
      {
        if (l > arr[i])
          l = arr[i];
        else
          r = arr[i];
      }
    }
    cout << res << '\n';
  }
  return 0;
}
