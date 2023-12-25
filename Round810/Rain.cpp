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

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, m{};
  cin >> n >> m;
  vector<PLLLL> rain(n);
  REP(i, n) { cin >> rain[i].first >> rain[i].second; }
  VI index(n);
  iota(ALL(index), 0);
  auto cmp = [&rain](int a, int b)
  {
    return rain[a].first < rain[b].first;
  };
  auto cmp1 = [&rain](int a, LL b)
  {
    return a < rain[b].first;
  };
  auto cmp2 = [&rain](int a, int b)
  {
    return rain[a].first < b;
  };
  sort(ALL(index), cmp);
  vector<LL> acc(n);
  vector<LL> intensity(n);
  VI countSub(n);
  int temp{}, temp1{};
  LL temp2{};
  REP(i, n)
  {
    temp2 = rain[index[i]].first + rain[index[i]].second;
    acc[i] += temp2;
    temp = lower_bound(ALL(index), temp2, cmp2) - index.begin();
    if (temp == n)
      continue;
    else
      acc[temp] -= temp2, ++countSub[temp];
  }
  intensity[index[0]] = acc[0] - rain[0].first;
  FOR(i, 1, n, 1)
  {
    acc[i] = acc[i - 1] + acc[i];
    countSub[i] = countSub[i] + countSub[i - 1];
    intensity[index[i]] = acc[i] - (i + 1 - countSub[i]) * rain[index[i]].first;
  }
  REP(i, n) { acc[i] = countSub[i] = 0; }
  RFOR(i, n - 1, 0, 1)
  {
    temp2 = rain[index[i]].second - rain[index[i]].first;
    acc[i] += temp2;
    temp = (upper_bound(ALL(index), -temp2, cmp1) - index.begin()) - 1;
    // DEBUG(acc, temp, temp2);
    if (temp < 0)
      continue;
    else
      acc[temp] -= temp2, ++countSub[temp];
  }
  // DEBUG(acc, countSub, intensity);
  RFOR(i, n - 2, 0, 1)
  {
    temp2 = rain[index[i]].second - rain[index[i]].first;
    acc[i] += acc[i + 1];
    countSub[i] += countSub[i + 1];
    intensity[index[i]] += acc[i] - temp2 + ((n - i - 1) - countSub[i]) * rain[index[i]].first;
  }
  VI maxLeft(n), maxRight(n);
  maxLeft[index.front()] = index.front(), maxRight[index.back()] = index.back();
  FOR(i, 1, n, 1)
  {
    if (intensity[index[i]] > intensity[maxLeft[index[i - 1]]])
      maxLeft[index[i]] = index[i];
    else
      maxLeft[index[i]] = maxLeft[index[i - 1]];
  }
  RREP(i, n - 2)
  {
    if (intensity[index[i]] > intensity[maxRight[index[i + 1]]])
      maxRight[index[i]] = index[i];
    else
      maxRight[index[i]] = maxRight[index[i + 1]];
  }

  bool isPossible{};
  VB ans(n);
  // DEBUG(rain, intensity, index, maxLeft, maxRight);
  REP(i, n)
  {
    isPossible = true;
    if (intensity[i] - rain[i].second > m)
      isPossible = false;
    else
    {
      temp = rain[maxLeft[i]].first + rain[i].second - rain[i].first;
      // DEBUG("Inner left", temp, intensity[maxLeft[i]]);
      if (temp > 0 && intensity[maxLeft[i]] - temp > m)
        isPossible = false;
      else
      {
        temp = rain[i].first + rain[i].second - rain[maxRight[i]].first;
        // DEBUG("Inner right", temp, intensity[maxRight[i]]);
        if (temp > 0 && intensity[maxRight[i]] - temp > m)
          isPossible = false;
      }
      if (isPossible)
      {
        temp = (upper_bound(ALL(index), rain[i].first - rain[i].second, cmp1) - index.begin()) - 1;
        // DEBUG("Left", temp);
        if (temp >= 0 && intensity[maxLeft[index[temp]]] > m)
          isPossible = false;
        else
        {
          temp = lower_bound(ALL(index), rain[i].first + rain[i].second, cmp2) - index.begin();
          // DEBUG("Right", temp);
          if (temp < n && intensity[maxRight[index[temp]]] > m)
            isPossible = false;
        }
      }
    }
    cout << (isPossible ? 1 : 0);
  }
  // REP(i, n) { cout << ans[i]; }
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
