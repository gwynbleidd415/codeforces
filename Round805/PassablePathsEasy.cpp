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
#define PB push_back
#define PF push_front
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
void fillTimer(int src, int par, vector<VI> &adj, VI &tin, VI &tout, int &timer)
{
  tin[src] = ++timer;
  FOREACH(it, adj[src])
  {
    if (it != par)
      fillTimer(it, src, adj, tin, tout, timer);
  }
  tout[src] = ++timer;
}

void fillEuler(int src, int par, vector<VI> &adj, VI &euler, vector<PII> &firstLastEul, VI &depths, int curDepth)
{
  euler.push_back(src);
  firstLastEul[src].first = firstLastEul[src].second = SIZE(euler) - 1;
  depths[src] = curDepth;
  FOREACH(itr, adj[src])
  {
    if (itr != par)
    {
      fillEuler(itr, src, adj, euler, firstLastEul, depths, curDepth + 1);
      euler.push_back(src);
      firstLastEul[src].second = SIZE(euler) - 1;
    }
  }
}

void fillLogTable(VI &logTable, int n)
{
  logTable[0] = 0;
  logTable[1] = 0;
  FOR(i, 2, n + 1, 1) { logTable[i] = logTable[i / 2] + 1; }
}

void fillMinSparse(VI &euler, VI &depths, vector<VI> &minSparse, int r, int c)
{
  REP(i, r) { minSparse[i][0] = euler[i]; }
  int nxt{1}, till{r - nxt};
  for (int j{1}; j < c; ++j)
  {
    for (int i{0}; i < till; ++i)
      minSparse[i][j] = depths[minSparse[i][j - 1]] <= depths[minSparse[i + nxt][j - 1]] ? minSparse[i][j - 1] : minSparse[i + nxt][j - 1];
    nxt <<= 1;
    till = r - nxt;
  }
}

// bool solveQuery(VI &query, VI &tin, VI &tout)
// {
//   int cntBreak{0};
//   FOR(i, 1, SIZE(query), 1)
//   {
//     if (tin[query[i]] > tin[query[i - 1]])
//     {
//       ++cntBreak;
//       if (cntBreak > 1)
//         break;
//     }
//   }
//   return (cntBreak <= 1);
// }

bool solveQuery(VI &euler, VI &query, vector<PII> &firstLastEul, VI &depths, vector<VI> &minSparse, VI &logTable)
{
  // DEBUG(minSparse);
  // DEBUG(query);
  // DEBUG(euler);
  // DEBUG(firstLastEul);
  bool cntBreak{false};
  int feua{}, feub{}, logg{}, lca{}, minspa, minspb;
  FOR(i, 1, SIZE(query), 1)
  {
    feua = firstLastEul[query[i]].first, feub = firstLastEul[query[i - 1]].first;
    if (feua > feub)
    {
      // DEBUG(cntBreak);
      if (cntBreak)
        return false;
      else
      {
        logg = logTable[feua - feub + 1];
        minspa = minSparse[feub][logg], minspb = minSparse[feua - (1 << logg) + 1][logg];
        lca = depths[minspa] <= depths[minspb] ? minspa : minspb;
        // DEBUG(query[i], query[i - 1]);
        // DEBUG(logg, minspa, minspb, lca);
        if (firstLastEul[lca].first <= firstLastEul[query.back()].first && firstLastEul[lca].second >= firstLastEul[query.back()].second)
          cntBreak = true;
        else
          return false;
      }
    }
  }
  return true;
}

VB solve(int n, int q, vector<VI> &adj, vector<VI> &queries)
{
  VB ans(q);
  // VI tin(n + 1), tout(n + 1);
  VI depths(n + 1), euler;
  vector<PII> firstLastEul(n + 1);
  fillEuler(1, 0, adj, euler, firstLastEul, depths, 0);
  // DEBUG(ans, depths, firstLastEul, euler);

  int srs{SIZE(euler)};
  VI logTable(srs + 1);
  fillLogTable(logTable, srs);
  int scs{logTable[srs] + 1};
  vector<VI> minSparse(srs, VI(scs));
  fillMinSparse(euler, depths, minSparse, srs, scs);
  // DEBUG(srs, logTable, scs, minSparse);

  // int timer{0};
  // fillTimer(1, 0, adj, tin, tout, timer);
  // auto cmp = [&tout](int a, int b)
  // {
  //   return tout[a] < tout[b];
  // };

  auto cmp = [&firstLastEul](int &a, int &b)
  {
    return firstLastEul[a].second < firstLastEul[b].second;
  };

  REP(i, q)
  {
    sort(ALL(queries[i]), cmp);
    // ans[i] = solveQuery(queries[i], tin, tout);
    ans[i] = solveQuery(euler, queries[i], firstLastEul, depths, minSparse, logTable);
  }
  return ans;
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, q{}, qn{}, t1{}, t2{};
  cin >> n;
  vector<VI> adj(n + 1);
  REP(i, n - 1)
  {
    cin >> t1 >> t2;
    adj[t1].push_back(t2);
    adj[t2].push_back(t1);
  }
  cin >> q;
  vector<VI> queries(q);
  REP(i, q)
  {
    cin >> qn;
    queries[i].resize(qn);
    REP(j, qn) { cin >> queries[i][j]; }
  }
  VB ans{solve(n, q, adj, queries)};
  FOREACH(it, ans) { cout << (it ? "YES" : "NO") << '\n'; }
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
