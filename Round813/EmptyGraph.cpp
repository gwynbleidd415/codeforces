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
int maxAns{(int)1e9};
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, k{};
  cin >> n >> k;
  VI arr(n);
  REP(i, n) { cin >> arr[i]; }
  // DEBUG(n, k, arr);
  if (k == n)
  {
    cout << maxAns << '\n';
    return;
  }
  if (k == 1)
  {
    int minInd{0};
    FOR(i, 1, n, 1)
    {
      if (arr[minInd] > arr[i])
        minInd = i;
    }
    arr[minInd] = maxAns;

    int minn{arr[0]}, maxn{INT_MIN};
    FOR(i, 1, n, 1)
    {
      if (minn > arr[i])
        minn = arr[i];
      maxn = max(maxn, min(arr[i], arr[i - 1]));
    }
    minn = min((LL)maxAns, (((LL)minn) << 1));
    cout << min(minn, maxn) << '\n';
    return;
  }
  auto cmp = [&arr](int i, int j)
  {
    return arr[i] > arr[j];
  };
  priority_queue<int, VI, decltype(cmp)> pq(cmp);
  REP(i, n - k) { pq.push(i); }
  int maxx{arr[pq.top()]};
  // DEBUG(maxx, pq.size());
  FOR(i, n - k, n, 1)
  {
    while (!pq.empty() && pq.top() <= i - (n - k))
      pq.pop();
    pq.push(i);
    maxx = max(maxx, arr[pq.top()]);
  }
  // DEBUG(maxx, pq.size());
  FOR(i, k, n, 1)
  {
    while (!pq.empty() && pq.top() <= k && pq.top() > i - k)
      pq.pop();

    pq.push(i - k);
    maxx = max(maxx, arr[pq.top()]);
  }
  // DEBUG(maxx, pq.size());

  int ans{(int)min((LL)maxAns, (((LL)maxx) << 1))};
  cout << ans << '\n';
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
