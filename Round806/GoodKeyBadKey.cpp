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

/*********************************** Main Solution Starts Here ***********************************/
vector<int> pow2(32);

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, k{};
  cin >> n >> k;
  VI arr(n);
  REP(i, n) { cin >> arr[i]; }
  int c{min(n, 30)};
  // vector<VLL> dp(n + 1, VLL(c));
  // dp[n - 1][c - 1] = max(arr[n - 1] / pow2[c - 1] - k, arr[n - 1] / pow2[c]);
  // RREP(i, n - 1)
  // {
  //   REP(j, c - 1)
  //   {
  //     dp[i][j] = max(dp[i + 1][j] + arr[i] / pow2[j] - k, dp[i + 1][j + 1] + arr[i] / pow2[j + 1]);
  //   }
  // }
  // cout << dp[0][0] << '\n';

  VLL dp(c + 1);
  LL temp1{}, temp2{};
  RREP(i, n - 1)
  {
    temp1 = 0;
    RREP(j, c)
    {
      temp2 = dp[j];
      dp[j] = max(dp[j] + arr[i] / pow2[j] - k, temp1 + arr[i] / pow2[j + 1]);
      temp1 = temp2;
    }
  }
  cout << dp[0] << '\n';
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  pow2[0] = 1;
  FOR(i, 1, 32, 1) { pow2[i] = 2 * pow2[i - 1]; }

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
