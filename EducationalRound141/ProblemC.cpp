#include <bits/stdc++.h>

using namespace std;

/*********************************** Main Solution Starts Here ***********************************/
const int MAX_N_SIZE = 500000;
int arr[MAX_N_SIZE], ind[MAX_N_SIZE];
int getIndex(int *arr, int n, int el)
{
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] == el)
      return i;
  }
  return n - 1;
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n;
  int m;
  cin >> n >> m;
  // vector<int> arr(n), ind(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
    ind[i] = i;
  }
  sort(ind, ind + n, [&](int &a, int &b)
       { return arr[a] <= arr[b]; });
  int ii{0};
  int mm{m};
  for (int i = 0; i < n; ++i)
  {
    if (arr[ind[i]] <= mm)
    {
      mm -= arr[ind[i]];
      ++ii;
    }
    else
    {
      break;
    }
  }
  if (ii == n)
  {
    cout << 1 << '\n';
    return;
  }
  if (ii == 0)
  {
    cout << n + 1 << '\n';
    return;
  }
  int jj = getIndex(ind, n, ii);
  if (jj < ii)
  {
    cout << n - ii << '\n';
    return;
  }
  int summ{arr[ii]};
  for (int i; i < ii - 1; ++i)
  {
    summ += arr[ind[i]];
  }
  if (summ <= m)
  {
    cout << n - ii << '\n';
    return;
  }
  cout << n + 1 - ii << '\n';
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
