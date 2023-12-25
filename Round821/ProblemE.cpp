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

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  LL n, x, y;
  cin >> n >> x >> y;
  string str1, str2;
  cin >> str1 >> str2;
  if (str1 == str2)
  {
    cout << 0 << '\n';
    return;
  }
  if (y <= x)
  {
    LL xor1{0}, lasti{-5};
    bool together{false};
    REP(i, n)
    {
      if (str1[i] != str2[i])
      {
        ++xor1;
        if (lasti + 1 == i)
        {
          together = true;
        }
        lasti = i;
      }
    }
    if (xor1 & 1)
    {
      cout << "-1\n";
      return;
    }
    LL divv{xor1 >> 1};
    if (divv > 1 || !together)
    {
      cout << (divv * y) << '\n';
      return;
    }
    if (x < y * 2)
    {
      cout << x << '\n';
    }
    else
    {
      cout << y * 2 << '\n';
    }
    return;
  }
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
    inputOutput();
  }
  return 0;
}
