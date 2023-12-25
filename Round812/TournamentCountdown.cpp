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
int ask(int a, int b)
{
  cout << "? " << a << " " << b << '\n';
  int tmp{};
  cin >> tmp;
  return tmp;
}

void printAns(int a)
{
  cout << "! " << a << '\n';
}

/**************************** Input/Output Handler ****************************/
bool inputOutput()
{
  int n{};
  cin >> n;

  int nn{1 << n};
  list<int> arr;
  FOR(i, 1, nn + 1, 1) { arr.push_back(i); }

  list<int>::iterator itr1, itr2, itr3, itr4;

  int tmp{};
  while (arr.size() > 2)
  {
    itr1 = arr.begin(), itr2 = prev(arr.end());
    while (next(itr2) != itr1)
    {
      tmp = ask(*itr1, *itr2);
      if (tmp == -1)
        return false;
      if (tmp == 0)
      {
        itr3 = itr1, itr4 = itr2;
        ++itr1, --itr2;
      }
      else if (tmp == 1)
      {
        itr3 = next(itr1);
        itr4 = itr2;
        --itr2;
      }
      else if (tmp == 2)
      {
        itr3 = itr1;
        itr4 = prev(itr2);
        ++itr1;
      }
      arr.erase(itr3), arr.erase(itr4);
      ++itr1, --itr2;
    }
  }

  tmp = ask(arr.front(), arr.back());
  if (tmp <= 0)
    return false;
  if (tmp == 1)
    printAns(arr.front());
  else
    printAns(arr.back());

  return true;
}

/**************************** Main Function *************************/
int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    if (!inputOutput())
      break;
  }
  return 0;
}
