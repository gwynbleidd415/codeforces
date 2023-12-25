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
#define CINARR(arr, n) \
  REP(i, n)            \
  {                    \
    cin >> arr[i];     \
  }
#define COUTARR(arr, n) \
  REP(i, n)             \
  {                     \
    cout << arr[i];     \
  }                     \
  cout << '\n';

/*********************************** Main Solution Starts Here ***********************************/
int getDigitSum(int n)
{
  int ans{0};
  while (n)
  {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n;
  cin >> n;
  int mid = n >> 1;
  if (!(n & 1))
  {
    cout << mid << ' ' << mid << '\n';
    return;
  }
  if (mid % 10 != 9)
  {
    cout << mid << ' ' << mid + 1 << '\n';
    return;
  }
  // int lo = getDigitSum(mid);
  // int hi = getDigitSum(mid + 1);
  int digitSum{getDigitSum(n)};
  int toRem{digitSum >> 1};
  int ans1{0}, ans2{n}, nc{n}, mult{1}, temp;
  while (true)
  {
    temp = nc % 10;
    if (temp >= toRem)
    {
      ans1 += toRem * mult;
      ans2 -= toRem * mult;
      break;
    }
    ans1 += temp * mult;
    ans2 -= temp * mult;
    toRem -= temp;
    mult *= 10;
    nc /= 10;
  }
  cout << ans1 << ' ' << ans2 << '\n';
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
