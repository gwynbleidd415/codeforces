#include <iostream>
#include <string>

using namespace std;

void clearArr(char *arr)
{
  for (int i{0}; i < 3; ++i)
    arr[i] = '\0';
}

bool isInArr(char *arr, int j, char ch)
{
  for (int i{0}; i < j; ++i)
    if (arr[i] == ch)
      return true;
  return false;
}

void inputOutput()
{
  string str{};
  cin >> str;
  int n{(int)str.size()};
  char arr[3];
  clearArr(arr);
  int ans{n == 0 ? 0 : 1}, j{0};
  for (int i{0}; i < n; ++i)
  {
    if (isInArr(arr, j, str[i]))
      continue;
    if (j == 3)
    {
      clearArr(arr);
      ++ans;
      j = 0;
    }
    arr[j++] = str[i];
  }
  cout << ans << '\n';
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
