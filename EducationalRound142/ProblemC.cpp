#include <bits/stdc++.h>

using namespace std;

/*********************************** ShortCuts for basic things ***********************************/
/**************************** Variable Shortcuts ****************************/
#define LL long long
#define UL unsigned long
#define ULL unsigned long long
#define LD long double
#define PII pair<int, int>
#define PLLLL pair<LL, LL>
#define VI vector<int>
#define VB vector<bool>
#define VD vector<double>
#define VLL vector<LL>
#define USET unordered_set
#define UMAP unordered_map
/**************************** Inbuilt Function Shortcuts ****************************/
#define LB lower_bound
#define UB upper_bound
/**************************** Common Function Shortcuts ****************************/
#define SIZE(x) ((int)x.size())
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, start, endExc, inc) for (int i = start; i < endExc; i += inc)
#define RFOR(i, start, endInc, dec) for (int i = start; i >= endInc; i -= dec)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FORI(itr, start, end) for (auto itr = start; itr != end; ++itr)
#define REPI(itr, obj) FORI(itr, ALL(obj))
#define FOREACH(it, l) for (auto const &it : l)
#define MFOREACH(it, l) for (auto &it : l)

/*********************************** Main Solution Starts Here ***********************************/
bool isBetween(int p1x1, int p1x2, int p2x1, int p2x2)
{
  if (p1x1 <= p2x1 && p2x1 <= p1x2 && p1x1 <= p2x2 && p2x2 <= p1x2)
    return true;
  return false;
}

void helper(int n, VI &index, int &mid1, int &mid2)
{
  int lsi{index[mid1]}, lei{index[mid2]};
  while (mid1 >= 1 && mid2 <= n)
  {
    if (index[mid1] > index[mid2] || !isBetween(index[mid1], index[mid2], lsi, lei))
      break;
    lsi = index[mid1], lei = index[mid2];
    --mid1, ++mid2;
  }
}

int priorityMid(int n, VI &arr, VI &index)
{
  int mid1{n >> 1};
  int mid2{mid1 + 1};
  if (n & 1)
  {
    ++mid2;
  }
  helper(n, index, mid1, mid2);
  if (mid1 == 0)
  {
    if (arr.front() == 1 && arr.back() == n)
      return 0;
    return 1;
  }
  return mid1 + (n & 1);
}

int priorityLeft(int n, VI &arr, VI &index)
{
  int mid1{n >> 1};
  int mid2{mid1 + 1};
  helper(n, index, mid1, mid2);
  if (mid1 == 0)
  {
    if (arr.back() == n)
      return 0;
    return 1;
  }
  return mid1 + (n & 1);
}

int priorityRight(int n, VI &arr, VI &index)
{
  int mid1{(n + 1) >> 1};
  int mid2{mid1 + 1};
  helper(n, index, mid1, mid2);
  if (mid2 > n)
  {
    if (arr.front() == 1)
      return 0;
    return 1;
  }
  return (n - mid2 + 1) + (n & 1);
}

int solve(int n, VI &arr)
{
  if (n == 1)
    return 0;
  VI index(n + 1);
  REP(i, n)
  {
    index[arr[i]] = i;
  }
  return min(priorityLeft(n, arr, index), priorityRight(n, arr, index));
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n;
  cin >> n;
  VI arr(n);
  REP(i, n) { cin >> arr[i]; }
  cout << solve(n, arr) << '\n';
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
