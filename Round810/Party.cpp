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
  int n{}, m{};
  cin >> n >> m;
  VI unhappiness(n + 1), count(n + 1, 0);
  vector<PII> mates(m);
  FOR(i, 1, n + 1, 1) { cin >> unhappiness[i]; }
  REP(i, m)
  {
    cin >> mates[i].first >> mates[i].second;
    ++count[mates[i].first], ++count[mates[i].second];
  }
  if (!(m & 1))
  {
    cout << 0 << '\n';
    return;
  }
  int ans{INT_MAX};
  REP(i, m)
  {
    if (!(count[mates[i].first] & 1) && !(count[mates[i].second] & 1))
      ans = min(ans, unhappiness[mates[i].first] + unhappiness[mates[i].second]);
    else
    {
      if (count[mates[i].first] & 1)
        ans = min(ans, unhappiness[mates[i].first]);
      if (count[mates[i].second] & 1)
        ans = min(ans, unhappiness[mates[i].second]);
    }
  }
  cout << ans << '\n';
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
