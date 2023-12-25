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
LL getNearest2(int num)
{
  while (num % 10 != 2)
    num = num + num % 10;
  return num;
}
/**************************** Input/Output Handler ****************************/
bool inputOutput()
{
  int n{};
  cin >> n;
  VLL arr(n);
  int c10{0};
  REP(i, n)
  {
    cin >> arr[i];
    if (arr[i] % 10 == 5)
      arr[i] += 5;
    if (arr[i] % 10 == 0)
      ++c10;
    else
      arr[i] = getNearest2(arr[i]);
  }
  if (c10 != 0)
  {
    REP(i, n - 1)
    {
      if (arr[i] != arr[i + 1])
        return false;
    }
    return true;
  }
  int a1 = arr[0];
  FOR(i, 1, n, 1)
  {
    if (labs(arr[i] - a1) % 20 != 0)
      return false;
  }
  return true;
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    if (inputOutput())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
