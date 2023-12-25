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
const int mod = 998244353;

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, k{};
  cin >> n >> k;

  int m{(int)sqrt(2 * n)};
  VI summ(n + 1);
  vector<VI> adj(n + 1, VI(2));
  FOR(i, k, n + 1, k) { summ[i] = adj[i][0] = 1; }

  int tmp{};
  bool tmpb{};
  FOR(j, 1, m, 1)
  {
    tmpb = j & 1;
    tmp = k + j;
    if (tmp <= n)
      adj[tmp - 1][tmpb] = adj[tmp - 2][tmpb] = 0;
    FOR(i, tmp, n + 1, 1)
    {
      adj[i][tmpb] = ((LL)adj[i - tmp][!tmpb] + adj[i - tmp][tmpb]) % mod;
      summ[i] = ((LL)summ[i] + adj[i][tmpb]) % mod;
    }
  }

  FOR(i, 1, n + 1, 1) { cout << summ[i] << ' '; }
  cout << '\n';
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int TC{1};
  // cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
