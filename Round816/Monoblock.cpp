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

/**************************** For Debugging ****************************/
void __PRINT(int x) { cerr << x; }
void __PRINT(long x) { cerr << x; }
void __PRINT(LL x) { cerr << x; }
void __PRINT(unsigned x) { cerr << x; }
void __PRINT(UL x) { cerr << x; }
void __PRINT(ULL x) { cerr << x; }
void __PRINT(float x) { cerr << x; }
void __PRINT(double x) { cerr << x; }
void __PRINT(LD x) { cerr << x; }
void __PRINT(char x) { cerr << '\'' << x << '\''; }
void __PRINT(const char *x) { cerr << '\"' << x << '\"'; }
void __PRINT(const string &x) { cerr << '\"' << x << '\"'; }
void __PRINT(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __PRINT(const pair<T, V> &x)
{
  cerr << '{';
  __PRINT(x.first);
  cerr << ',';
  __PRINT(x.second);
  cerr << '}';
}
template <typename T>
void __PRINT(const T &x)
{
  int f = 0;
  cerr << '{';
  for (auto const &i : x)
    cerr << (f++ ? "," : ""), __PRINT(i);
  cerr << "}";
}
void _PRINT() { cerr << "]\n"; }
template <typename T, typename... V>
void _PRINT(T t, V... v)
{
  __PRINT(t);
  if (sizeof...(v))
    cerr << ", ";
  _PRINT(v...);
}
#ifndef ONLINE_JUDGE
#define DEBUG(x...)             \
  cerr << "[" << #x << "] = ["; \
  _PRINT(x)
#else
#define DEBUG(x...)
#endif

/*********************************** Main Solution Starts Here ***********************************/
void modify(VI &arr, LL &sums, int i, int x)
{
  if (arr[i] == x)
    return;
  LL n{SIZE(arr)};
  bool waseql{false}, waseqr{false}, iseql{false}, iseqr{false};
  if (i > 0)
  {
    if (arr[i] == arr[i - 1])
    {
      // waseql = true, sums += i;
      sums += (n - i) * i;
    }
    else if (x == arr[i - 1])
    {
      // iseql = true, sums -= i;
      sums -= (n - i) * i;
    }
  }
  if (i < n - 1)
  {
    if (arr[i] == arr[i + 1])
    {
      // waseqr = true, sums += n - i - 1;
      sums += (n - i - 1) * (i + 1);
    }
    else if (x == arr[i + 1])
    {
      // iseqr = true, sums -= n - i - 1;
      sums -= (n - i - 1) * (i + 1);
    }
  }
  // DEBUG(arr, n, sums, i, x);
  arr[i] = x;
  // cout << "SUMS : " << i << x << sums << '\n';
  // if (!waseql && !waseqr && !iseql && !iseqr)
  //   return;
  // if ((waseql && iseqr) || (waseqr && iseql))
  //   return;
  // if (waseql && waseqr)
  // {
  //   sums += ((n - i - 1) * i) >> 1;
  //   return;
  // }
  // if (iseql && iseqr)
  // {
  //   sums -= ((n - i - 1) * i) >> 1;
  //   return;
  // }
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, m{};
  cin >> n >> m;
  VI arr(n);
  REP(i, n) { cin >> arr[i]; }
  VI tarr(n, 0);
  LL sums{((LL)n * (n + 1)) >> 1};
  REP(i, n) { modify(tarr, sums, i, arr[i]); }
  VLL ans(m);
  int x, y;
  REP(i, m)
  {
    cin >> x >> y;
    --x;
    modify(tarr, sums, x, y);
    ans[i] = sums;
  }
  REP(i, m) { cout << ans[i] << '\n'; }
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
