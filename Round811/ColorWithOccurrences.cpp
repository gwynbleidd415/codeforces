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
bool exists(string &str, string &arr, int n)
{
  int i{n};
  FOREACH(ch, arr)
  {
    if (str[i] == ch)
      ++i;
    else
      return false;
  }
  return true;
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  string str{};
  cin >> str;
  int n{};
  cin >> n;
  vector<string> arr(n);
  REP(i, n) { cin >> arr[i]; }
  VI index(n);
  iota(ALL(index), 0);
  sort(ALL(index), [&arr](int a, int b)
       { return arr[a].size() > arr[b].size(); });
  vector<USET<int>> mat(n);
  int temp{};
  REP(i, n)
  {
    temp = str.size() - arr[i].size() + 1;
    REP(j, temp)
    {
      if (exists(str, arr[i], j))
        mat[i].insert(j);
    }
  }
  // DEBUG(str, n, arr, index, mat);
  int l{0}, r{0}, maxx{0}, ans{0};
  vector<PII> anss;
  PII tanss;
  while (r < str.size())
  {
    maxx = r;
    FOR(i, l, r + 1, 1)
    {
      REP(j, n)
      {
        if (mat[index[j]].find(i) != mat[index[j]].end())
        {
          if (SIZE(arr[index[j]]) + i > maxx)
          {
            maxx = SIZE(arr[index[j]]) + i;
            tanss = {index[j], i};
          }
        }
      }
    }
    if (maxx == r)
      break;
    ++ans;
    anss.push_back(tanss);
    r = maxx;
    ++l;
  }
  if (r < str.size())
  {
    cout << "-1\n";
    return;
  }
  cout << ans << '\n';
  FOREACH(itr, anss)
  {
    cout << itr.first + 1 << ' ' << itr.second + 1 << '\n';
  }
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
