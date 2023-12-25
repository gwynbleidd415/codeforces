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
bool canFill(int n, int m, int k, vector<LL> &pigments)
{
  bool isOddFiller{false}, greaterThan2{false};
  LL temp{}, cnt{0};
  REP(i, k)
  {
    temp = pigments[i] / m;
    if (temp < 2)
      continue;
    if (temp & 1)
      isOddFiller = true;
    if (temp > 2)
      greaterThan2 = true;
    cnt += temp;
  }
  if (cnt < n)
    return false;
  if (!(n & 1) || isOddFiller)
    return true;
  if (cnt > n && greaterThan2)
    return true;
  return false;
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, m{}, k{};
  cin >> n >> m >> k;
  vector<LL> pigments(k);
  REP(i, k) { cin >> pigments[i]; }
  if (canFill(n, m, k, pigments) || canFill(m, n, k, pigments))
    cout << "YES\n";
  else
    cout << "NO\n";
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
