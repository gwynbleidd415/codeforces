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
#define RFOR(i, start, endInc, dec) for (int i = start; i >= endInc; i -= inc)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FORI(itr, start, end) for (auto itr = start; itr != end; ++itr)
#define REPI(itr, obj) FORI(itr, ALL(obj))
#define FOREACH(it, l) for (auto const &it : l)

/*********************************** Main Solution Starts Here ***********************************/

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{};
  cin >> n;
  vector<VB> matrix(n, VB(n));
  char temp{};
  REP(i, n)
  {
    REP(j, n)
    {
      cin >> temp;
      matrix[i][j] = (temp == '1');
    }
  }
  int r{(n >> 1)}, n1{n - 1};
  int i1{}, i2{}, j1{}, j2{};
  int ans{0}, tcnt{};
  REP(i, r)
  {
    i1 = i, i2 = n1 - i;
    tcnt = 0;
    FOR(j, i, n1 - i, 1)
    {
      j1 = j, j2 = n1 - j;
      tcnt = (int)matrix[i1][j1] + matrix[j1][i2] + matrix[i2][j2] + matrix[j2][i1];
      if (tcnt % 4 == 0)
        continue;
      if (tcnt == 2)
        ans += 2;
      else
        ans += 1;
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
