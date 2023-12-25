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
void dfs(int par, LL summ, vector<VI> &children, vector<PII> &arr, VI &ans, VLL &temp)
{
  LL summ1{};
  int i{};
  FOREACH(itr, children[par])
  {
    temp.push_back(temp.back() + arr[itr].second);
    summ1 = summ + arr[itr].first;
    // i = ans[par] + 1;
    // while (i < SIZE(temp) && temp[i] <= summ1)
    //   ++i;
    // ans[itr] = i - 1;
    int lo{ans[par] + 1}, hi{SIZE(temp)}, mid{};
    while (lo < hi)
    {
      mid = (lo + hi) >> 1;
      if (temp[mid] <= summ1)
        lo = mid + 1;
      else
        hi = mid;
    }
    ans[itr] = lo - 1;
    dfs(itr, summ1, children, arr, ans, temp);
    temp.pop_back();
  }
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{};
  cin >> n;
  vector<PII> arr(n);
  vector<VI> children(n);
  int tp{};
  FOR(i, 1, n, 1)
  {
    cin >> tp >> arr[i].first >> arr[i].second;
    children[tp - 1].push_back(i);
  }
  VI ans(n);
  ans[0] = 0;
  VLL temp{0};
  dfs(0, 0, children, arr, ans, temp);
  FOR(i, 1, n, 1) { cout << ans[i] << ' '; }
  cout << '\n';
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
