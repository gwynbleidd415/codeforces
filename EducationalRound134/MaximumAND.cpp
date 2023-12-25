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
int getAns(VI &A, VI &B, int st, int ed, int trac)
{
  int bi{st}, aj{ed};
  for (int i{st}; i <= ed; ++i)
  {
    if (B[i] & trac)
      swap(B[i], B[bi]), ++bi;
  }
  for (int i{ed}; i >= st; --i)
  {
    if (A[i] & trac)
      swap(A[i], A[aj]), --aj;
  }
  // DEBUG(A, B, st, ed, trac, aj, bi);
  return ((bi == (aj + 1)) ? aj : -10);
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n;
  cin >> n;
  VI A(n), B(n);

  REP(i, n) { cin >> A[i]; }
  REP(i, n) { cin >> B[i]; }

  int ans{INT_MAX >> 1}, trac{1 << 29};

  vector<PII> qu, qu1, qu2;
  qu.push_back({0, n - 1});
  PII top{};

  while (trac)
  {
    qu1 = qu;
    qu2.clear();
    bool isPossible(true);
    while (qu1.size())
    {
      top = qu1.back();
      qu1.pop_back();
      int ga = getAns(A, B, top.first, top.second, trac);
      if (ga == -10)
      {
        isPossible = false;
        break;
      }
      else
      {
        if (ga >= top.first)
          qu2.push_back({top.first, ga});
        if (ga < top.second)
          qu2.push_back({ga + 1, top.second});
      }
    }

    if (isPossible)
    {
      qu = qu2;
    }
    else
    {
      ans = ans & (~trac);
    }
    trac = trac >> 1;
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

// 10
// 8
// 28 14 12 27 10 8 27 27
// 5 23 17 2 21 19 6 22
// 5
// 4 2 7 11 25
// 27 29 24 20 6
// 3
// 6 18 21
// 25 15 8
// 13
// 28 12 15 14 2 28 10 10 4 25 19 5 15
// 23 11 16 17 9 23 1 9 19 22 12 18 8
// 5
// 28 19 4 3 10
// 1 12 25 28 21
// 1
// 28
// 3
// 3
// 23 5 22
// 0 16 3
// 3
// 27 30 0
// 0 5 9
// 20
// 18 16 21 16 26 15 21 17 30 13 22 21 30 18 0 11 11 20 1 29
// 9 15 10 11 1 20 10 10 5 22 9 14 1 13 31 20 16 11 26 2
// 1
// 11
// 14
