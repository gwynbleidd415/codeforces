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
  int m{};
  cin >> m;
  vector<VI> adj(2, VI(m));
  REP(i, 2)
  {
    REP(j, m) { cin >> adj[i][j]; }
  }
  vector<VI> waitRight(2, VI(m)), waitLeft(2, VI(m));
  waitRight[0][m - 1] = adj[0][m - 1] - m, waitRight[1][m - 1] = adj[1][m - 1] - m;
  waitLeft[0][m - 1] = adj[0][m - 1] - (m - 1), waitLeft[1][m - 1] = adj[1][m - 1] - (m - 1);
  RREP(i, m - 2)
  {
    waitRight[0][i] = max(waitRight[0][i + 1], adj[0][i] - ((m << 1) - i - 1));
    waitRight[1][i] = max(waitRight[1][i + 1], adj[1][i] - ((m << 1) - i - 1));
  }
  RREP(i, m - 2)
  {
    waitLeft[0][i] = max(waitLeft[0][i + 1], adj[0][i] - i);
    waitLeft[1][i] = max(waitLeft[1][i + 1], adj[1][i] - i);
  }
  LL ans{max(waitLeft[0][1], waitRight[1][1]) + 1 + (LL)((m - 1) << 1)}, cur{adj[1][0] + 1};
  ans = max(ans, (LL)adj[1][0]) + 1;
  int tmp{};
  LL tmp1{};
  bool btmp{};
  FOR(i, 1, m, 1)
  {
    btmp = i & 1;
    tmp = max(waitLeft[btmp][i], waitRight[!btmp][i]) + i;
    tmp1 = max((LL)tmp, cur);
    ans = min(ans, tmp1 + ((m - i) << 1));
    cur = max(cur, (LL)adj[btmp][i]) + 1;
    cur = max(cur, (LL)adj[!btmp][i]) + 1;
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
