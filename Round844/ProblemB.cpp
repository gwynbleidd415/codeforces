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
const int MAX_N = 2e5;
int arr[MAX_N];

LL getAnswer(int n)
{
  LL ans{0};
  sort(arr, arr + n);
  int start{n - 1};
  while (start >= 0)
  {
    while (start >= 0 && arr[start] > start)
      --start;
    if (start < 0)
      break;
    ++ans;
    int stop = arr[start] - 1;
    while (stop >= 0)
    {
      if (arr[stop] > stop)
      {
        break;
      }
      else
      {
        stop = arr[stop] - 1;
      }
    }
    start = stop - 1;
  }
  if (arr[0] > 0)
    ++ans;
  return ans;
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n;
  cin >> n;
  REP(i, n) { cin >> arr[i]; }
  cout << getAnswer(n) << '\n';
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
